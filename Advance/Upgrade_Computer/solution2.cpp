#include <iostream>
#define MAX_N 30
#define MAX_M 40
using namespace std;
int So_linh_kien, So_goi_uu_dai, So_luong_can_mua, ans;
int Gia_cho_troi[MAX_N];
int Gia_cac_goi_uu_dai[MAX_M];
int Linh_kien_cac_goi_uu_dai[MAX_M][MAX_N];
int Cac_thiet_bi_can_mua[MAX_N + 1];

bool Goi_uu_dai_co_thiet_bi(int index_goi);
int Du_linh_kien();
void excecute(int curr_price, int index_linhKien, int index_goi);
void reset();
void input();

int main() {
    freopen("input.txt", "r", stdin);
    int Testcase;
    cin >> Testcase;
    for (int tc = 1; tc <= Testcase; tc++) {
        reset();
        input();
        excecute(0, 0, 0);
        cout << "#" << tc << " ";
        cout << ans << endl;
    }
    return 0;
}

bool Goi_uu_dai_co_thiet_bi(int index_goi) {
    int i = 0;
    while (Linh_kien_cac_goi_uu_dai[index_goi][i]) {
        if (Cac_thiet_bi_can_mua[Linh_kien_cac_goi_uu_dai[index_goi][i]])
            return true;
        else
            i++;
    }
    return false;
}

int Du_linh_kien() {
    for (int i = 0; i < MAX_N + 1; i++) {
        if (Cac_thiet_bi_can_mua[i] > 0)
            return 0;
    }
    return 1;
}

void excecute(int curr_price, int index_linhKien, int index_goi) {
    if (Du_linh_kien()) {
        if (ans > curr_price)
            ans = curr_price;
        return;
    }

    for (int index = 0; index < 2; index++) {
        if (index == 0) // mua linh kien cho den
        {
            if (index_linhKien > So_linh_kien)
                return;
            if (Cac_thiet_bi_can_mua[index_linhKien]) {
                Cac_thiet_bi_can_mua[index_linhKien]--;
                if ((curr_price + Gia_cho_troi[index_linhKien]) < ans)
                    excecute(curr_price + Gia_cho_troi[index_linhKien], index_linhKien + 1, index_goi);
                Cac_thiet_bi_can_mua[index_linhKien]++;
            }

            else
                excecute(curr_price, index_linhKien + 1, index_goi);
        } else // mua theo combo
        {
            int Cac_thiet_bi[MAX_N] = {0};
            if (index_goi > So_goi_uu_dai)
                return;
            if (Goi_uu_dai_co_thiet_bi(index_goi)) {
                int i = 0;
                int soluong = 0;
                while (Linh_kien_cac_goi_uu_dai[index_goi][i]) {
                    if (Cac_thiet_bi_can_mua[Linh_kien_cac_goi_uu_dai[index_goi][i]]) {
                        Cac_thiet_bi_can_mua[Linh_kien_cac_goi_uu_dai[index_goi][i]]--;
                        Cac_thiet_bi[soluong] = Linh_kien_cac_goi_uu_dai[index_goi][i];
                        soluong++;
                    }
                    i++;
                }
                if ((curr_price + Gia_cac_goi_uu_dai[index_goi]) < ans)
                    excecute(curr_price + Gia_cac_goi_uu_dai[index_goi], index_linhKien, index_goi + 1);

                for (int i = 0; i < soluong; i++) {
                    Cac_thiet_bi_can_mua[Cac_thiet_bi[i]]++;
                }
            } else
                excecute(curr_price, index_linhKien, index_goi + 1);
        }
    }
}

void reset() {
    ans = 1e9;
    for (int i = 0; i < MAX_N + 1; i++)
        Cac_thiet_bi_can_mua[i] = 0;
    for (int i = 0; i < MAX_N; i++) {
        Gia_cho_troi[i] = 0;
    }

    for (int i = 0; i < MAX_M; i++) {
        Gia_cac_goi_uu_dai[i] = 0;
        for (int j = 0; j < MAX_N; j++)
            Linh_kien_cac_goi_uu_dai[i][j] = 0;
    }
}

void input() {
    cin >> So_linh_kien;
    for (int i = 0; i < So_linh_kien; i++)
        cin >> Gia_cho_troi[i + 1];
    cin >> So_goi_uu_dai;
    for (int i = 0; i < So_goi_uu_dai; i++) {
        cin >> Gia_cac_goi_uu_dai[i];
        int a;
        cin >> a;
        for (int j = 0; j < a; j++)
            cin >> Linh_kien_cac_goi_uu_dai[i][j];
    }
    cin >> So_luong_can_mua;
    for (int i = 0; i < So_luong_can_mua; i++) {
        int a;
        cin >> a;
        Cac_thiet_bi_can_mua[a] = 1;
    }
}