#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
    int a, b;
    int max = 0;   /* 当前发现的最大上课时长（仅当 > 8 时考虑） */
    int idx = 0;   /* 记录最不高兴的那天（1..7），0 表示不会不高兴 */
    for (int i = 0; i < 7; i++)
    {
        scanf("%d %d", &a, &b);
        int sum = a + b;
        if (sum > 8 && sum > max) {
            max = sum;
            idx = i + 1; /* 按题要求，周一为 1 */
        }
    }
    printf("%d", idx);
    return 0;
}

//int main()
//{
//	int arr[7][2];
//	for (int i = 0; i < 7; i++)
//	{
//		for (int k = 0; k < 2; k++)
//		{
//			scanf("%d", &arr[i][k]);
//		}
//	}
//	int arr2[7] = { 0,0,0,0,0,0,0 };
//	for (int i = 0; i < 7; i++)
//	{
//		if (arr[i][0] + arr[i][1] > 8)
//		{
//			arr2[i] = (arr[i][0] + arr[i][1]);
//		}
//	}
//	for (int i = 0; i < 7; i++)
//	{
//		for (int k = (i+1); k < 7; k++)
//			if (arr2[i] == arr2[k])
//				arr2[k] = 0;
//	}
//	int x = 0;
//	for (int i = 0; i < 7; i++)
//	{
//		if (arr2[i] > arr2[0])
//		{
//			x = i;
//			arr2[0] = arr2[i];
//		}
//	}
//	printf("%d", x+1);
//	return 0;
//}

//int main()
//{
//    int y = 0;
//    int m = 0;
//    scanf("%d %d", &y, &m);
//    if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
//    {
//        if (m == 2)
//            printf("29");
//        else if (m <= 7 && m % 2 == 1)
//            printf("31");
//        else if (m <= 7 && m % 2 == 0 && m != 2)
//            printf("30");
//        else if (m > 7 && m % 2 == 0)
//            printf("31");
//        else if (m > 7 && m % 2 == 1)
//            printf("30");
//    }
//    else
//    {
//        if (m == 2)
//            printf("28");
//        else if (m <= 7 && m % 2 == 1)
//            printf("31");
//        else if (m <= 7 && m % 2 == 0 && m != 2)
//            printf("30");
//        else if (m > 7 && m % 2 == 0)
//            printf("31");
//        else if (m > 7 && m % 2 == 1)
//            printf("30");
//    }
//    return 0;
//}

//#include<stdio.h>
//
//int main()
//{
//    int a, b, c;
//    scanf("%d %d %d ", &a, &b, &c);
//    if (a == b && a == c)
//    {
//        printf("%d %d %d", a, b, c);
//        return 0;
//    }
//    if (a < b && a < c && b < c)
//        printf("%d %d %d", a, b, c);
//    else if (a < b && a < c && c < b)
//        printf("%d %d %d", a, c, b);
//    else if (b < a && b < c && a < c)
//        printf("%d %d %d", b, a, c);
//    else if (b < a && b < c && c < a)
//        printf("%d %d %d", b, c, a);
//    else if (c < a && c < b && b < a)
//        printf("%d %d %d", c, b, a);
//    else 
//        printf("%d %d %d", c, a, b);
//    return 0;
//}


//int main()
//{
//	float a = 1.0200;
//	printf("%g", a);
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include <math.h>
//
///* 方法1：使用 %g（最简单）
// * %g 会使用指定的有效数字数（默认6）并去掉末尾的零与不必要的小数点。
// * 注意：当数值很大或很小时，%g 可能会使用指数形式（e）。如果不想要指数形式，
// * 可以用后面的方案把数四舍五入到固定小数位再去尾零。
// */
//
// /* 方法2：用 snprintf 按固定小数位格式化，然后手动去掉末尾的0和可能遗留的小数点 */
//char* trim_trailing_zeros(float v, int fixed_decimals)
//{
//    char buf[128];
//    /* 使用 double 是因为可变参数会把 float 提升为 double */
//    snprintf(buf, sizeof buf, "%.*f", fixed_decimals, (double)v);
//
//    /* 去掉末尾的'0' */
//    char* p = buf + strlen(buf) - 1;
//    while (p > buf && *p == '0') {
//        *p = '\0';
//        --p;
//    }
//    /* 如果最后是小数点，去掉它 */
//    if (p > buf && *p == '.') {
//        *p = '\0';
//    }
//    return strdup(buf); /* 调用者需 free() 返回指针 */
//}
//
///* 方法3：先把数值按一定小数位四舍五入，再用方法2格式化并去零。
// * 这样能避免浮点表示导致的“0.100000001”类问题。我们先尝试找最小的
// * 小数位数（不超过 max_decimals）能使得四舍五入后的值与原值足够接近。
// */
//static float pow10f_int(int n) {
//    float r = 1.0f;
//    while (n-- > 0) r *= 10.0f;
//    return r;
//}
//
//int minimal_decimals_for_value(float v, int max_decimals, float eps)
//{
//    for (int d = 0; d <= max_decimals; ++d) {
//        float p = pow10f_int(d);
//        float rounded = roundf(v * p) / p;
//        if (fabsf(rounded - v) <= eps) return d;
//    }
//    return max_decimals;
//}
//
//char* format_float_minimal(float v, int max_decimals, float eps)
//{
//    int d = minimal_decimals_for_value(v, max_decimals, eps);
//    /* 先按 d 位四舍五入，再格式化并去尾零 */
//    float p = pow10f_int(d);
//    float rounded = roundf(v * p) / p;
//    char* s = trim_trailing_zeros(rounded, d);
//    return s;
//}
//
//int main(void)
//{
//    float a = 3.140000f;
//    float b = 3.000000f;
//    float c = 0.0001200f;
//    float d = 1.2345600f;
//    float e = 0.1f; /* 注意浮点精度问题 */
//
//    printf("使用 %%g (默认精度6):\n");
//    printf("a -> %g\n", (double)a);
//    printf("b -> %g\n", (double)b);
//    printf("c -> %g\n", (double)c);
//    printf("d -> %g\n", (double)d);
//    printf("e -> %g\n", (double)e);
//
//    printf("\n使用 %%.*f + 去尾零 (固定小数位后去零):\n");
//    char* s;
//    s = trim_trailing_zeros(a, 9); printf("a -> %s\n", s); free(s);
//    s = trim_trailing_zeros(b, 9); printf("b -> %s\n", s); free(s);
//    s = trim_trailing_zeros(c, 9); printf("c -> %s\n", s); free(s);
//    s = trim_trailing_zeros(d, 9); printf("d -> %s\n", s); free(s);
//    s = trim_trailing_zeros(e, 9); printf("e -> %s\n", s); free(s);
//
//    printf("\n先四舍五入找最小小数位再去零（max_decimals=9, eps=1e-6）:\n");
//    s = format_float_minimal(a, 9, 1e-6f); printf("a -> %s\n", s); free(s);
//    s = format_float_minimal(b, 9, 1e-6f); printf("b -> %s\n", s); free(s);
//    s = format_float_minimal(c, 9, 1e-6f); printf("c -> %s\n", s); free(s);
//    s = format_float_minimal(d, 9, 1e-6f); printf("d -> %s\n", s); free(s);
//    s = format_float_minimal(e, 9, 1e-6f); printf("e -> %s\n", s); free(s);
//
//    return 0;
//}

//#include<stdio.h>
//
//int main()
//{
//    int m, t, s;
//    scanf("%d %d %d", &m, &t, &s);
//    if (t == 0)
//    {
//        printf("0");
//        return 0;
//    }
//    int num = (s + t - 1) / t;
//    int fm = m - num;
//    if (num > m)
//        printf("0");
//    else if (num <= m)
//        printf("%d", fm);
//    return 0;
//}