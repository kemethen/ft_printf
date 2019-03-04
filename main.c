/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 12:16:52 by kemethen          #+#    #+#             */
/*   Updated: 2019/03/04 18:41:47 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/ft_printf.h"
#include <stdio.h>

int		main(void)
{
int             nb;
        nb = -45;
        ft_printf("space% d\n", nb);
        ft_printf("plus:%+d\n", nb);
        ft_printf("precision:%.5d\n", nb);
        ft_printf("space + prec:% .5d\n", nb);
        ft_printf("Plus + prec / grande:%+.5d\n", nb);
        ft_printf("Plus + prec / petite:%+.0d\n", nb);
        ft_printf("Prec + 0:%0.5d\n", nb);
        ft_printf("Prec + minus:%-.5d\n", nb);
        ft_printf("size:%5d\n", nb);
        ft_printf("size + space:% 5d\n", nb);
        ft_printf("size + plus:%+5d\n", nb);
        ft_printf("size + minus:%-5d\n", nb);
        ft_printf("size + 0:%05d\n", nb);
        ft_printf("size + 0 + plus:%+05d\n", nb);
        ft_printf("size + 0 + plus:%0+5d\n", nb);
        ft_printf("size + 0 + prec:%05.3d\n", nb);
        ft_printf("size + minus + prec:%-5.3d\n", nb);
        ft_printf("size + plus + 0 + prec:%+05.3d\n", nb);
        ft_printf("size + espace + zero + prec:%0 5.3d\n", nb);
        ft_printf("size + espace + zero + prec:% 05.3d\n", nb);
        ft_printf("size + minus + plus + prec:%-+5.3d\n", nb);

        dprintf(2, "space% d\n", nb);
        dprintf(2, "plus:%+d\n", nb);
        dprintf(2, "precision:%.5d\n", nb);
        dprintf(2, "space + prec:% .5d\n", nb);
        dprintf(2, "Plus + prec / grande:%+.5d\n", nb);
        dprintf(2, "Plus + prec / petite:%+.0d\n", nb);
        dprintf(2, "Prec + 0:%0.5d\n", nb);
        dprintf(2, "Prec + minus:%-.5d\n", nb);
        dprintf(2, "size:%5d\n", nb);
        dprintf(2, "size + space:% 5d\n", nb);
        dprintf(2, "size + plus:%+5d\n", nb);
        dprintf(2, "size + minus:%-5d\n", nb);
        dprintf(2, "size + 0:%05d\n", nb);
        dprintf(2, "size + 0 + plus:%+05d\n", nb);
        dprintf(2, "size + 0 + plus:%0+5d\n", nb);
        dprintf(2, "size + 0 + prec:%05.3d\n", nb);
        dprintf(2, "size + minus + prec:%-5.3d\n", nb);
        dprintf(2, "size + plus + 0 + prec:%+05.3d\n", nb);
        dprintf(2, "size + espace + zero + prec:%0 5.3d\n", nb);
        dprintf(2, "size + espace + zero + prec:% 05.3d\n", nb);
        dprintf(2, "size + minus + plus + prec:%-+5.3d\n", nb);

        ft_printf("space% i\n", nb);
        ft_printf("plus:%+i\n", nb);
        ft_printf("precision:%.5i\n", nb);
        ft_printf("space + prec:% .5i\n", nb);
        ft_printf("Plus + prec / grande:%+.5i\n", nb);
        ft_printf("Plus + prec / petite:%+.0i\n", nb);
        ft_printf("Prec + 0:%0.5i\n", nb);
        ft_printf("Prec + minus:%-.5i\n", nb);
        ft_printf("size:%5i\n", nb);
        ft_printf("size + space:% 5i\n", nb);
        ft_printf("size + plus:%+5i\n", nb);
        ft_printf("size + minus:%-5i\n", nb);
        ft_printf("size + 0:%05i\n", nb);
        ft_printf("size + 0 + plus:%+05i\n", nb);
        ft_printf("size + 0 + plus:%0+5i\n", nb);
        ft_printf("size + 0 + prec:%05.3i\n", nb);
        ft_printf("size + minus + prec:%-5.3i\n", nb);
        ft_printf("size + plus + 0 + prec:%+05.3i\n", nb);
        ft_printf("size + espace + zero + prec:%0 5.3i\n", nb);
        ft_printf("size + espace + zero + prec:% 05.3i\n", nb);
        ft_printf("size + minus + plus + prec:%-+5.3i\n", nb);

        dprintf(2, "space% i\n", nb);
        dprintf(2, "plus:%+i\n", nb);
        dprintf(2, "precision:%.5i\n", nb);
        dprintf(2, "space + prec:% .5i\n", nb);
        dprintf(2, "Plus + prec / grande:%+.5i\n", nb);
        dprintf(2, "Plus + prec / petite:%+.0i\n", nb);
        dprintf(2, "Prec + 0:%0.5i\n", nb);
        dprintf(2, "Prec + minus:%-.5i\n", nb);
        dprintf(2, "size:%5i\n", nb);
        dprintf(2, "size + space:% 5i\n", nb);
        dprintf(2, "size + plus:%+5i\n", nb);
        dprintf(2, "size + minus:%-5i\n", nb);
        dprintf(2, "size + 0:%05i\n", nb);
        dprintf(2, "size + 0 + plus:%+05i\n", nb);
        dprintf(2, "size + 0 + plus:%0+5i\n", nb);
        dprintf(2, "size + 0 + prec:%05.3i\n", nb);
        dprintf(2, "size + minus + prec:%-5.3i\n", nb);
        dprintf(2, "size + plus + 0 + prec:%+05.3i\n", nb);
        dprintf(2, "size + espace + zero + prec:%0 5.3i\n", nb);
        dprintf(2, "size + espace + zero + prec:% 05.3i\n", nb);
        dprintf(2, "size + minus + plus + prec:%-+5.3i\n", nb);


        close(pipeans[1]);
        close(pipecor[1]);
        ians = read(pipeans[0], ans, READING_SIZE);
        icor = read(pipecor[0], cor, READING_SIZE);
        close(pipeans[0]);
        close(pipecor[0]);
        ans[ians] = 0;
        cor[icor] = 0;
        if (strcmp(cor, ans) == 0)
                exit (SUCCESS);
        exit(FAILURE);
}
