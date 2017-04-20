var express = require('express');
var app = express();
var server = require('http').createServer(app);
var io = require('socket.io').listen(server);
var expr_sess = require('express-session');
var bodyParser = require('body-parser');
var mysql      = require('mysql');
var nodemailer = require('nodemailer');
var ent = require('ent');
var md5 = require('md5');


var urlencodedParser = bodyParser.urlencoded({ extended: false });
app.use(expr_sess({secret: 'secretterizyqflhu', resave: false, saveUninitialized: false}));

var transporter = nodemailer.createTransport({
	service: 'gmail',
	auth: {
		user: 'dirty.trash.mel@gmail.com',
		pass: 'dtmdtmdtm'
	}
});
var connection = mysql.createConnection({
	host     : 'localhost',
	user     : 'root',
	password : 'dirty',
	database : '_matcha'
});

connection.connect();

// connection.query('select * from bonjour;', function (error, results, fields) {
//   if (error) throw error;
//   console.log(JSON.stringify(results));
// });
 
// connection.end();

function createActivationKey(id_user, meladress) {
	console.log('Creating activation key...');
	console.log(id_user);
	var ran = Math.random();
	console.log(ran)
	console.log(md5(ran));
	connection.query('insert into activateAccount (id_user, u_key) values (?, ?)', [id_user, md5(ran)], function(err, resq, fld) {
		if (err) throw err;
		console.log('clé créée dans activateAccount');
		var mailOptions = {
			from: '"Pony pony run run 👻" <foo@blurdybloop.com>', // sender address
			to: meladress, // list of receivers
			subject: 'Bienvenu sur Matcha ✔', // Subject line
			text: 'Cliquez sur le lien ci dessous pour confirmer votre inscription:\n http://localhost:8080/activate-account/' 
			+ id_user + '/' + md5(ran) // plain text body
			//, html: '<b>Hello world ?</b>' // html body
		};
		// send mail with defined transport object
		transporter.sendMail(mailOptions, function(error, info) {
			if (error) {
				return console.log(error);
			}
			console.log('Message %s sent: %s', info.messageId, info.response);
		});
	});
}

function getUserId(name, meladress, callback) {
	console.log('looking for...');
	console.log(name);
	var res = connection.query('select id from users where name=?', [name], function(err, resq, fld) {
		if (err) throw err;
		console.log(resq);
		if (callback){
			console.log('Callback');
			callback(resq[0].id, meladress);
		}
		else
			console.log('NONONO PAS de CB');
	});
}

app.use(express.static('public'));

app.get('/', function(req, res) {
	console.log('\033[0;34m' + __dirname + '\033[0m');
	if (!req.session.logged){
		res.redirect('/login');
		return ;
	}
	else{
		res.render('index.ejs', {username: req.session.logged});
	}
	
})
.get('/login', function(req, res) {
	if (req.session.logged){
		res.redirect('/');
		return ;
	}
	res.render('login.ejs', {_message: req.session._message});
	req.session._message = undefined;
})
.post('/login-attempt', urlencodedParser, function(req, res) {
	if (req.session.logged || !req.body.username || !req.body.password){
		res.redirect('/');
		return ;
	}
	connection.query('select id, name, actif from users where name=? and password=?', [req.body.username, req.body.password], function(err, resq, fld) {
		if (err) throw err;
		if (resq[0] && resq[0].actif == 1) {
			console.log('User ' + resq[0].name + ' se connecte');
			req.session.logged = resq[0].name;
		}
		else if (resq[0] && (!resq[0].actif || resq[0].actif == 0)) {
			console.log('User doit encore activer son compte');
			req.session._message = {message: "Vous devez activer votre compte.", color: 'yellow'};
		}
		else {
			console.log('\033[0;31m' + 'User mot de passe erronné ou username faux' + '\033[0m');
			req.session._message = {message: "Le nom d'utilisateur ou le mot de passe est erroné.", color: 'red'};
		}
		res.redirect('/');
	});

})
.get('/create-account', function(req, res) {
	if (req.session.logged){
		res.redirect('/');
		return ;
	}
	res.render('create_account.ejs');
})
.post('/create-account-req', urlencodedParser, function(req, res) {
	connection.query('select name from users where name=?', [req.body.username], function(err, resq, fields) {
		if (err) throw err;
		if (resq.length == 0 && req.body.username && req.body.password && req.body.lastname && req.body.firstname && req.body.meladress) {
			connection.query("insert into users (name, password, firstname, lastname, meladress, actif) values (?, ?, ?, ?, ?, 0)", [req.body.username, req.body.password, req.body.firstname, req.body.lastname, req.body.meladress], function(err, resq, fld) {
				if (err) throw err;
				getUserId(req.body.username, req.body.meladress, createActivationKey);
				req.session._message = {message: 'Un mail vous a été envoyé, veuillez cliquer sur le lien pour activer votre compte.', color: 'blue'};
				// req.session._message = {message: 'Votre compte a bien été créé.', color: 'blue'};
				res.redirect('/');
			});
		}
		else {
			req.session._message = {message: 'Ce nom d\'utilisateur n\'est pas disponible.', color: 'red'};
			res.redirect('/');
		}
	});
})
.get('/activate-account/:id_user/:u_key', function(req, res) {
	var id_user = req.params.id_user;
	var u_key = req.params.u_key;
	connection.query('select id_user from activateAccount where id_user=? and u_key=?', [id_user, u_key], function(err, resq, fld) {
		if (err) throw err;
		console.log(resq);
		if (resq[0]) {
			connection.query('update users set actif=1 where id=?', [resq[0].id_user], function(err, resq2, fld) {
				if (err) throw err;
				//reset la clé dactivation pour safety
				connection.query('update activateAccount set u_key=? where id_user=?', [md5(Math.random()), resq[0].id_user], function(err, resq2, fld) {
					if (err) throw err;
				});
			});
			req.session._message = {message: "Vous venez d'activer votre compte vous pouvez maintenant vous connecter.", color: 'blue'};
			res.redirect('/');
		}
		else
			res.end('bad Morning');
	});
})
.get('/sign-out', function(req, res) {
	// req.session.logged = undefined;
	req.session.destroy();
	res.redirect('/');
})
.get('/forgot-pwd', function(req, res) {
	if (req.session.logged){
		res.redirect('/');
		return ;
	}
	res.render('forgot_pwd.ejs');
})
.post('/forgot-pwd-req', urlencodedParser, function(req, res) {
	connection.query('select id, meladress from users where name=? and meladress=?', [req.body.username, req.body.meladress], function(err, resq, fld) {
		if (err) throw err;
		if (resq.length == 0) {
			console.log('mauvaise combinaison login meladress pour forgot_pwd');
			req.session._message = {message: "Utilisateur inconnu ou adresse email non correspondante.", color: 'red'};
			res.redirect('/');
		}
		else {
			var ran = md5(Math.random());
			console.log('Notre rand dans forgot-pwd-req: ' + ran);
			connection.query('select id from activateAccount where id_user=?', [resq[0].id], function (err, resq2, fld) {
				if (resq2.length == 0) {
					connection.query('insert into activateAccount (id_user, u_key) values (?, ?)', [resq[0].id, ran], function (err, resq3, fld) {
						if (err) throw err;
					});
				}
				else if (resq2.length == 1) {
					connection.query('update activateAccount set u_key=? where id=?', [ran, resq2[0].id], function (err, resq3, fld) {
						if (err) throw err;
					});
				}
				else {
					console.log('Ya un probleme, plus qu\'un id_user');
					req.session._message = {message: "Erreur au moment de la création de la clé d'activation", color: 'red'};
					res.redirect('/');
					return ;
				}
			});
			var mailOptions = {
				from: '"Pony pony run run 👻" <foo@blurdybloop.com>', // sender address
				to: resq[0].meladress, // list of receivers
				subject: 'Matcha - réinitialiser votre mot de passe', // Subject line
				text: 'Cliquez sur le lien ci dessous pour réinitialiser votre mot de passe:\n http://localhost:8080/forgot-pwd-reset/' 
				+ resq[0].id + '/' + ran // plain text body
				//, html: '<b>Hello world ?</b>' // html body
			};
			// send mail with defined transport object
			transporter.sendMail(mailOptions, function(error, info) {
				if (error) {
					return console.log(error);
				}
				console.log('Message %s sent: %s', info.messageId, info.response);
			});
			req.session._message = {message: "Un mail vous à été envoyé pour réinitialiser votre mot de passe.", color: 'blue'};
			res.redirect('/');
		}
	});
})
.get('/forgot-pwd-reset/:id_user/:u_key', function(req, res) {
	if (req.session.logged){
		res.redirect('/');
		return ;
	}
	res.render('forgot_pwd_reset.ejs', {id_user: req.params.id_user, u_key: req.params.u_key});
})
.post('/new-pwd/:id_user/:u_key', urlencodedParser, function(req, res) {
	if (req.session.logged){
		res.redirect('/');
		return ;
	}
	//verifier que le user n'essaie pas de modifier le mdp d'un autre user
	var id_user = req.params.id_user;
	var u_key = req.params.u_key;
	connection.query('select id from activateAccount where id_user=? and u_key=?', [id_user, u_key], function (err, resq, fld) {
		if (err) throw err;
		if (resq.length == 0) {
			req.session._message = {message: "Une erreur est survenue lors de la tentative de changement de votre mot de passe veuillez rééssayer.", color: 'red'};
			res.redirect('/');
			return ;
		}
	//enregistrer le mdp dans la bdd et le set actif si ce n'est deja fait;
		connection.query('update users set password=?, actif=1 where id=?', [req.body.password, id_user], function (err, resq, fld) {
			if (err) throw err;
			req.session._message = {message: "Votre mot de passe à bien été changé.", color: 'blue'};
			res.redirect('/');
		});
	});
})
.get('/profil/:u_name', function(req, res) {
	if (!req.session.logged) {
		res.redirect('/');
		return ;
	}
	var name = req.params.u_name;
	connection.query('select * from users where name=?', name, function (err, resq, fld) {
		if (err) throw err;
		if (resq.length != 1) {
			res.redirect('/');
			return ;
		}
		if (name == req.session.logged)
			resq[0].isUser = true;
		connection.query('select tag from tags inner join relationUserTags on tags.id = relationUserTags.id_tag where id_user=?', [resq[0].id], function (err, resq2, fld) {
			if (err) throw err;
			connection.query('select path_to_img as path from userImgs where id_user=?', [resq[0].id], function (err, resq3, fld) {
				if (err) throw err;
				res.render('profil.ejs', { uDescription: resq[0], uTags: resq2, uName: req.session.logged, uImgs: resq3 });
			});
		});
	});
	
})
.get('/modify_profil', function (req, res) {
	if (!req.session.logged) {
		res.redirect('/');
		return ;
	}
	connection.query('select id, name, firstname, lastname, meladress, sex, target, bio from users where name=?', [req.session.logged], function (err, resq, fld) {
		if (err) throw err;
		console.log(resq);
		if (resq.length != 1) {
			res.redirect('/');
			return ;
		}
		connection.query('select tag from tags inner join relationUserTags on tags.id = relationUserTags.id_tag where id_user=?', [resq[0].id], function (err, resq2, fld) {
			if (err) throw err;
			connection.query('select path_to_img as path from userImgs where id_user=?', [resq[0].id], function (err, resq3, fld) {
				if (err) throw err;
				connection.query('select tag from tags', function (err, resq4, fld) {
					if (err) throw err;
					console.log(resq4);
					res.render('modify_profil.ejs', { userInfo: resq[0], userTags: resq2.map(function(obj) {return obj.tag;}), userImgs: resq3, allTags: resq4.map(function(obj) {return obj.tag;}) });
					// res.render('profil.ejs', { uDescription: resq[0], uTags: resq2, uName: req.session.logged, uImgs: resq3 });
				});
			});
		});
	});
});

io.sockets.on('connection', function(socket) {
	// console.log(socket.id);
});

server.listen('8080')







// side notes

// le retour d'une requete sql avec ce template mysql retourne toujours un tableau dans resq, vide si la requete n'a pas matché,
// pour chaque ligne matché un objet est créé, resq[0] est la premiere ligne et on peut acceder par exemple a id avec resq[0].id
// a la condition biensur que la requete demandait cette colonne.