/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 14:46:06 by afollin           #+#    #+#             */
/*   Updated: 2014/03/27 17:58:24 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "rt.h"
#include "libft.h"








#include <stdio.h>







int			main(int ac, char **av)
{
	t_obj		*tobj;

	if (!(tobj = (t_obj *)malloc(sizeof(t_obj))))
		return (-1);
	if (ac == 2)
	{
		ft_parse_obj(av[1], tobj);
	}
	write(1, "LOL\n", 4);
/* box0 */
	ft_putnbr_fd((((t_box ***)tobj->type)[0][0])->sf.b, 2);
	ft_putnbr_fd((((t_box ***)tobj->type)[0][0])->sf.g, 2);
	ft_putnbr_fd((((t_box ***)tobj->type)[0][0])->sf.r, 2);
	write(1, "\n", 1);
	ft_putnbr_fd((((t_box ***)tobj->type)[0][0])->em.b, 2);
	ft_putnbr_fd((((t_box ***)tobj->type)[0][0])->em.g, 2);
	ft_putnbr_fd((((t_box ***)tobj->type)[0][0])->em.r, 2);
	write(1, "\n", 1);
	ft_putnbr_fd((((t_box ***)tobj->type)[0][0])->xmin, 2);
	write(1, "\n", 1);
	ft_putnbr_fd((((t_box ***)tobj->type)[0][0])->xmax, 2);
	write(1, "\n", 1);
	ft_putnbr_fd((((t_box ***)tobj->type)[0][0])->ymin, 2);
	write(1, "\n", 1);
	ft_putnbr_fd((((t_box ***)tobj->type)[0][0])->ymax, 2);
	write(1, "\n", 1);
	ft_putnbr_fd((((t_box ***)tobj->type)[0][0])->zmin, 2);
	write(1, "\n", 1);
	ft_putnbr_fd((((t_box ***)tobj->type)[0][0])->zmax, 2);

	write(1, "\n", 1);
	write(1, "\n", 1);
	write(1, "\n", 1);
/* sphere0 */
	ft_putnbr_fd((((t_sph ***)tobj->type)[1][0])->sf.b, 2);
	ft_putnbr_fd((((t_sph ***)tobj->type)[1][0])->sf.g, 2);
	ft_putnbr_fd((((t_sph ***)tobj->type)[1][0])->sf.r, 2);
	write(1, "\n", 1);
	ft_putnbr_fd((((t_sph ***)tobj->type)[1][0])->em.b, 2);
	ft_putnbr_fd((((t_sph ***)tobj->type)[1][0])->em.g, 2);
	ft_putnbr_fd((((t_sph ***)tobj->type)[1][0])->em.r, 2);
	write(1, "\n", 1);
	ft_putnbr_fd((((t_sph ***)tobj->type)[1][0])->c.x, 2);
	ft_putnbr_fd((((t_sph ***)tobj->type)[1][0])->c.y, 2);
	ft_putnbr_fd((((t_sph ***)tobj->type)[1][0])->c.z, 2);
	write(1, "\n", 1);
	ft_putnbr_fd((((t_sph ***)tobj->type)[1][0])->r, 2);

	write(1, "\n", 1);
	write(1, "\n", 1);
	write(1, "\n", 1);
/* box1 */
	ft_putnbr_fd((((t_box ***)tobj->type)[0][1])->sf.b, 2);
	ft_putnbr_fd((((t_box ***)tobj->type)[0][1])->sf.g, 2);
	ft_putnbr_fd((((t_box ***)tobj->type)[0][1])->sf.r, 2);
	write(1, "\n", 1);
	ft_putnbr_fd((((t_box ***)tobj->type)[0][1])->em.b, 2);
	ft_putnbr_fd((((t_box ***)tobj->type)[0][1])->em.g, 2);
	ft_putnbr_fd((((t_box ***)tobj->type)[0][1])->em.r, 2);
	write(1, "\n", 1);
	ft_putnbr_fd((((t_box ***)tobj->type)[0][1])->xmin, 2);
	write(1, "\n", 1);
	ft_putnbr_fd((((t_box ***)tobj->type)[0][1])->xmax, 2);
	write(1, "\n", 1);
	ft_putnbr_fd((((t_box ***)tobj->type)[0][1])->ymin, 2);
	write(1, "\n", 1);
	ft_putnbr_fd((((t_box ***)tobj->type)[0][1])->ymax, 2);
	write(1, "\n", 1);
	ft_putnbr_fd((((t_box ***)tobj->type)[0][1])->zmin, 2);
	write(1, "\n", 1);
	printf("%f\n", (((t_box ***)tobj->type)[0][1])->zmax);

	write(1, "\n", 1);
	write(1, "\n", 1);
/* plan0 */
	ft_putnbr_fd((((t_pla ***)tobj->type)[2][0])->sf.b, 2);
	ft_putnbr_fd((((t_pla ***)tobj->type)[2][0])->sf.g, 2);
	ft_putnbr_fd((((t_pla ***)tobj->type)[2][0])->sf.r, 2);
	write(1, "\n", 1);
	ft_putnbr_fd((((t_pla ***)tobj->type)[2][0])->em.b, 2);
	ft_putnbr_fd((((t_pla ***)tobj->type)[2][0])->em.g, 2);
	ft_putnbr_fd((((t_pla ***)tobj->type)[2][0])->em.r, 2);
	write(1, "\n", 1);
	printf("%f ", (((t_pla ***)tobj->type)[2][0])->c.x);
	printf("%f ", (((t_pla ***)tobj->type)[2][0])->c.y);
	printf("%f\n", (((t_pla ***)tobj->type)[2][0])->c.z);
	printf("%f ", (((t_pla ***)tobj->type)[2][0])->n.x);
	printf("%f ", (((t_pla ***)tobj->type)[2][0])->n.y);
	printf("%f\n", (((t_pla ***)tobj->type)[2][0])->n.z);
	
	write(1, "\n", 1);
	write(1, "\n", 1);
/* disk0 */
	ft_putnbr_fd((((t_dis ***)tobj->type)[3][0])->sf.b, 2);
	ft_putnbr_fd((((t_dis ***)tobj->type)[3][0])->sf.g, 2);
	ft_putnbr_fd((((t_dis ***)tobj->type)[3][0])->sf.r, 2);
	write(1, "\n", 1);
	ft_putnbr_fd((((t_dis ***)tobj->type)[3][0])->em.b, 2);
	ft_putnbr_fd((((t_dis ***)tobj->type)[3][0])->em.g, 2);
	ft_putnbr_fd((((t_dis ***)tobj->type)[3][0])->em.r, 2);
	write(1, "\n", 1);
	printf("%f ", (((t_dis ***)tobj->type)[3][0])->c.x);
	printf("%f ", (((t_dis ***)tobj->type)[3][0])->c.y);
	printf("%f\n", (((t_dis ***)tobj->type)[3][0])->c.z);
	printf("%f ", (((t_dis ***)tobj->type)[3][0])->n.x);
	printf("%f ", (((t_dis ***)tobj->type)[3][0])->n.y);
	printf("%f\n", (((t_dis ***)tobj->type)[3][0])->n.z);
	printf("%f\n", (((t_dis ***)tobj->type)[3][0])->r);

	write(1, "\n", 1);
	write(1, "\n", 1);
/* cone0 */
	ft_putnbr_fd((((t_con ***)tobj->type)[4][0])->sf.b, 2);
	ft_putnbr_fd((((t_con ***)tobj->type)[4][0])->sf.g, 2);
	ft_putnbr_fd((((t_con ***)tobj->type)[4][0])->sf.r, 2);
	write(1, "\n", 1);
	ft_putnbr_fd((((t_con ***)tobj->type)[4][0])->em.b, 2);
	ft_putnbr_fd((((t_con ***)tobj->type)[4][0])->em.g, 2);
	ft_putnbr_fd((((t_con ***)tobj->type)[4][0])->em.r, 2);
	write(1, "\n", 1);
	printf("%f ", (((t_con ***)tobj->type)[4][0])->c.x);
	printf("%f ", (((t_con ***)tobj->type)[4][0])->c.y);
	printf("%f\n", (((t_con ***)tobj->type)[4][0])->c.z);
	printf("%f\n", (((t_con ***)tobj->type)[4][0])->o);
	printf("%f\n", (((t_con ***)tobj->type)[4][0])->rotx);
	printf("%f\n", (((t_con ***)tobj->type)[4][0])->roty);
	printf("%f\n", (((t_con ***)tobj->type)[4][0])->rotz);

	write(1, "\n", 1);
	write(1, "\n", 1);
/* cylindre0 */
	ft_putnbr_fd((((t_cyl ***)tobj->type)[5][0])->sf.b, 2);
	ft_putnbr_fd((((t_cyl ***)tobj->type)[5][0])->sf.g, 2);
	ft_putnbr_fd((((t_cyl ***)tobj->type)[5][0])->sf.r, 2);
	write(1, "\n", 1);
	ft_putnbr_fd((((t_cyl ***)tobj->type)[5][0])->em.b, 2);
	ft_putnbr_fd((((t_cyl ***)tobj->type)[5][0])->em.g, 2);
	ft_putnbr_fd((((t_cyl ***)tobj->type)[5][0])->em.r, 2);
	write(1, "\n", 1);
	printf("%f ", (((t_cyl ***)tobj->type)[5][0])->c.x);
	printf("%f ", (((t_cyl ***)tobj->type)[5][0])->c.y);
	printf("%f\n", (((t_cyl ***)tobj->type)[5][0])->c.z);
	printf("%f\n", (((t_cyl ***)tobj->type)[5][0])->r);
	printf("%c\n", (((t_cyl ***)tobj->type)[5][0])->flag);

	write(1, "\n", 1);
	write(1, "\n", 1);
/* disk1 */
	ft_putnbr_fd((((t_dis ***)tobj->type)[3][1])->sf.b, 2);
	ft_putnbr_fd((((t_dis ***)tobj->type)[3][1])->sf.g, 2);
	ft_putnbr_fd((((t_dis ***)tobj->type)[3][1])->sf.r, 2);
	write(1, "\n", 1);
	ft_putnbr_fd((((t_dis ***)tobj->type)[3][1])->em.b, 2);
	ft_putnbr_fd((((t_dis ***)tobj->type)[3][1])->em.g, 2);
	ft_putnbr_fd((((t_dis ***)tobj->type)[3][1])->em.r, 2);
	write(1, "\n", 1);
	printf("%f ", (((t_dis ***)tobj->type)[3][1])->c.x);
	printf("%f ", (((t_dis ***)tobj->type)[3][1])->c.y);
	printf("%f\n", (((t_dis ***)tobj->type)[3][1])->c.z);
	printf("%f ", (((t_dis ***)tobj->type)[3][1])->n.x);
	printf("%f ", (((t_dis ***)tobj->type)[3][1])->n.y);
	printf("%f\n", (((t_dis ***)tobj->type)[3][1])->n.z);
	printf("%f\n", (((t_dis ***)tobj->type)[3][1])->r);

	write(1, "\n", 1);
	write(1, "\n", 1);
/* disk2 */
	ft_putnbr_fd((((t_dis ***)tobj->type)[3][2])->sf.b, 2);
	ft_putnbr_fd((((t_dis ***)tobj->type)[3][2])->sf.g, 2);
	ft_putnbr_fd((((t_dis ***)tobj->type)[3][2])->sf.r, 2);
	write(1, "\n", 1);
	ft_putnbr_fd((((t_dis ***)tobj->type)[3][2])->em.b, 2);
	ft_putnbr_fd((((t_dis ***)tobj->type)[3][2])->em.g, 2);
	ft_putnbr_fd((((t_dis ***)tobj->type)[3][2])->em.r, 2);
	write(1, "\n", 1);
	printf("%f ", (((t_dis ***)tobj->type)[3][2])->c.x);
	printf("%f ", (((t_dis ***)tobj->type)[3][2])->c.y);
	printf("%f\n", (((t_dis ***)tobj->type)[3][2])->c.z);
	printf("%f ", (((t_dis ***)tobj->type)[3][2])->n.x);
	printf("%f ", (((t_dis ***)tobj->type)[3][2])->n.y);
	printf("%f\n", (((t_dis ***)tobj->type)[3][2])->n.z);
	printf("%f\n", (((t_dis ***)tobj->type)[3][2])->r);

	write(1, "\n", 1);
	return (0);
}
