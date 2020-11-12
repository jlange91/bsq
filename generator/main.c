#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>

#define EMPTY '.'
#define OBSTACLE 'o'
#define FULL 'x'

#include <stdint.h>

uint64_t xorshift64(uint64_t memory)
{
	uint64_t x = memory;
	x ^= x << 13;
	x ^= x >> 7;
	x ^= x << 17;
	return x;
}

int	int_len(int nb)
{
	int ret;

	ret = 0;
	while (nb)
	{
		nb /= 10;
		ret++;
	}
	return (ret);
}

int int_pow(int x, int n)
{
    int r = 1;
    while (n--)
        r *= x;

    return r; 
}

void	put_first_line(char *buf, int y)
{
	int i;
	int y_len = int_len(y);
	int max = y_len + 4;
	int pow;

	i = 0;
	while (y_len)
	{
		pow = int_pow(10, y_len - 1);
		buf[i] = y / pow + 48;
		y %= pow;
		--y_len;
		++i;
	}
	buf[i] = EMPTY;
	buf[i + 1] = OBSTACLE;
	buf[i + 2] = FULL;
	buf[i + 3] = '\n';
}

int main(int ac, char **av)
{
	char *buf;
	int density;
	int x;
	int y;
	unsigned long max;

	if (ac < 4)
	{
		write(1, "./program x y density\n", 22);
		return (0);
	}
	x = atoi(av[1]);
	y = atoi(av[2]);
	density = atoi(av[3]);
	max = x * y + y + (int_len(y) + 4);
	if (!(buf = (char*)malloc(sizeof(char) * max)))
		return (0);
	buf[max] = 0;
	put_first_line(buf, y);
	int i = int_len(y) + 4;
	int tx = 0;
	while (i < max)
	{
		buf[i] = ((xorshift64((uint64_t)&buf[i]) % y) < density) ? OBSTACLE : EMPTY;
		++tx;
		++i;
		if (tx >= x)
		{
			tx = 0;
			buf[i] = '\n';
			++i;
		}
	}
	write(1, buf, max);
	free(buf);
	return (0);
}
