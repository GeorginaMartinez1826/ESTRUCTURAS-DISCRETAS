#include <windows.h>
#include <commctrl.h>
#include "resource.h"
HINSTANCE hInst;

void F(HRGN hRgn, int x, int y, int a) {
    if (a > 5) {
        F(hRgn, x - a, y - a, a / 2);
        F(hRgn, x + a, y - a, a / 2);
        F(hRgn, x - a, y + a, a / 2);
        F(hRgn, x + a, y + a, a / 2);
    }
    HRGN hCuadrado = CreateRectRgn(x - a, y - a, x + a, y + a);
    CombineRgn(hRgn, hRgn, hCuadrado, RGN_OR);
    DeleteObject(hCuadrado);
}

BOOL CALLBACK DlgMain(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    if (uMsg == WM_PAINT) 
    {
        const int dx[4] = { 0, -1, 0, 1 }, dy[4] = { -1, 0, 1, 0 };
        const int px[4] = { 0, -1, -1, 0 }, py[4] = { -1, -1, 0, 0 };
        
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwndDlg, &ps);
        RECT r, c;
        GetClientRect(hwndDlg, &r);
        FillRect(hdc, &r, (HBRUSH)GetStockObject(WHITE_BRUSH));

        HRGN g = CreateRectRgn(0, 0, 0, 0);
        F(g, r.right / 2, r.bottom / 2, 40);
        GetRgnBox(g, &c);

        int x = c.right, y = c.top, d = 0, n = 0, i;
        while (!PtInRegion(g, x - 1, y)) y++;
        while (PtInRegion(g, x - 1, y)) y++;
        int xs = x, ys = y;
        MoveToEx(hdc, x, y, NULL);
        do {
            x += dx[d]; y += dy[d];
            LineTo(hdc, x, y);
            if (++n % 4 == 0) { GdiFlush(); Sleep(5); }
            i = (d + 1) % 4;
            if (!PtInRegion(g, x + px[i], y + py[i])) d = i;
            else if (PtInRegion(g, x + px[d], y + py[d])) d = (d + 3) % 4;
        } while (x != xs || y != ys || d != 0);

        DeleteObject(g);
        EndPaint(hwndDlg, &ps);
        return TRUE;
    }
    if (uMsg == WM_SIZE) { InvalidateRect(hwndDlg, NULL, TRUE); return TRUE; }
    if (uMsg == WM_CLOSE) { EndDialog(hwndDlg, 0); return TRUE; }
    return uMsg == WM_INITDIALOG;
}

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    hInst = hInstance;
    InitCommonControls();
    return DialogBox(hInst, MAKEINTRESOURCE(DLG_MAIN), NULL, (DLGPROC)DlgMain);
}