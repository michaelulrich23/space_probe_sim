#include <stdio.h>
double df_value(double A, double g, double H);
short int s_value(double h, double de, double v, double vsoft);
double h_value(double h, double v, double dt, double a);
double v_value(double v, double a, double dt);

int main() {
    double m, T, H, g, vsoft, dt, df, de, A, v=0, h, t=0, a;
    short int s;
    int total=0, max=0, temp=0;
    scanf("%lf %lf %lf %lf %lf %lf", &m, &T, &H, &g, &vsoft, &dt);

    printf("m=%0.3lf\n", m);
    printf("T=%0.3lf\n", T);
    printf("H=%0.3lf\n", H);
    printf("g=%0.3lf\n", g);
    printf("vsoft=%0.3lf\n", vsoft);
    printf("dt=%0.3lf\n", dt);

    A = T/m;
    df = df_value(A, g, H);
    de = H - df;

    printf("de=%0.3lf\n", de);
    h = H;
    while(h > 0){
        s = s_value(h, de, v, vsoft);

        printf("s=%d h=%08.3lf t=%0.3lf v=%0.3lf\n", s, h, t, v);
        if(s)
        {
            total = total + 1;
            temp = temp + 1;
            a = A - g;
            if (temp > max)
                max = temp;
        }
        else
        {
            temp = 0;
            a = -g;
        }
        h = h_value(h, v, dt, a);
        v = v_value(v, a, dt);
        t = t + dt;
    }
    printf("---Landed---\n");
    printf("%-5s=%08.3lf\n", "h", h);
    printf("%-5s=%8.3lf\n", "t", t);
    printf("%-5s=%8.3lf\n", "v", v);
    printf("%-5s=%4d\n", "total", total);
    printf("%-5s=%4d\n", "max", max);

    return 0;
}

double df_value(double A, double g, double H){
    double df;
    df = ((A-g)*H)/A;
    return df;
}

short int s_value(double h, double de, double v, double vsoft){
    short int s;
    if(h <= de && v<vsoft)
        s = 1;
    else
        s = 0;
    return s;
}

double h_value(double h, double v, double dt, double a){
    double h_new;
    h_new = h + v*dt + (a*(dt*dt))/2;
    return h_new;
}

double v_value(double v, double a, double dt){
    double v_new;
    v_new = v + a*dt;
    return v_new;
}