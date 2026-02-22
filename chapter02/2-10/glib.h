// glib.h - gnuplot を使ったグラフィクスライブラリ代替実装
#ifndef GLIB_H
#define GLIB_H

#include <stdio.h>
#include <stdlib.h>

#define _GMAX 10000

typedef struct { double x1, y1, x2, y2; int col; } _GLine;
static _GLine _gl[_GMAX];
static int _gn = 0;
static double _gcx, _gcy;
static double _gwx1, _gwy1, _gwx2, _gwy2;
static int _gcol = 0;

static void _gplot(void) {
    FILE *gp = popen("gnuplot -persistent", "w");
    if (!gp) { fprintf(stderr, "gnuplot が見つかりません\n"); return; }
    fprintf(gp, "set xrange [%f:%f]\n", _gwx1, _gwx2);
    fprintf(gp, "set yrange [%f:%f]\n", _gwy1, _gwy2);
    fprintf(gp, "unset key\n");
    for (int i = 0; i < _gn; i++) {
        const char *color = (_gl[i].col == 0) ? "black" : "red";
        fprintf(gp, "set arrow %d from %f,%f to %f,%f nohead lc rgb '%s'\n",
                i+1, _gl[i].x1, _gl[i].y1, _gl[i].x2, _gl[i].y2, color);
    }
    fprintf(gp, "plot NaN\n");
    pclose(gp);
}

static void ginit(void) {
    _gn = 0; _gcol = 0;
    atexit(_gplot);
}

static void window(double x1, double y1, double x2, double y2) {
    _gwx1=x1; _gwy1=y1; _gwx2=x2; _gwy2=y2;
}

static void line(double x1, double y1, double x2, double y2) {
    if (_gn < _GMAX) {
        _gl[_gn].x1=x1; _gl[_gn].y1=y1;
        _gl[_gn].x2=x2; _gl[_gn].y2=y2;
        _gl[_gn].col=_gcol;
        _gn++;
    }
}

static void setpoint(double x, double y) {
    _gcx=x; _gcy=y; _gcol=1;
}

static void moveto(double x, double y) {
    line(_gcx, _gcy, x, y);
    _gcx=x; _gcy=y;
}

#endif
