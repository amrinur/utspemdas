#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;




int main() {
    int mhs, mk;
    vector<string> nama_mk, nama_mhs;
    vector<vector<double>> nilai_mk, rata_rata_mhs, nilai_rata_mk;
    double total = 0.0, rata_rata = 0.0;
    double nilai_tertinggi = 0.0, nilai_terendah = 100.0;

    cout << "\t\t ------- Program UTS Kelompok 3 --------\n\n" << endl;

    cout << "Masukkan jumlah mahasiswa: ";
    cin >> mhs;
    cin.ignore();

    cout << "Masukkan jumlah mata kuliah: ";
    cin >> mk;
    cin.ignore();

    for (int k = 0; k < mk; k++) {
        string nama;
        cout << "Masukkan nama mata kuliah ke- " << k + 1 << ": ";
        getline(cin, nama);
        nama_mk.push_back(nama);
    }

    for (int i = 0; i < mhs; i++) {
        string nama;
        vector<double> nilai;
        double sum = 0.0; // reset nilai sum untuk setiap mahasiswa
        cout << "Masukkan nama mahasiswa ke-" << i + 1 << ": ";
        getline(cin, nama);
        nama_mhs.push_back(nama);

        for (int j = 0; j < mk; j++) {
            double nilai_input;
            total = 0.0;
            cout << "Masukkan nilai " << nama_mk[j] << " untuk mahasiswa " << nama << ": ";
            cin >> nilai_input;
            nilai.push_back(nilai_input);
            sum += nilai_input;

            if (nilai_input > nilai_tertinggi) {
                nilai_tertinggi = nilai_input;
            }
            if (nilai_input < nilai_terendah) {
                nilai_terendah = nilai_input;
            }
        }
        nilai_mk.push_back(nilai);
        cin.ignore();

        total += sum;

        rata_rata = static_cast<double>(total) / (mhs * mk);

        double rata = 0.0;
        for (int j = 0; j < mk; j++) {
            rata += nilai_mk[i][j];
        }
        rata /= mk;

        if (rata >= 80) {
            cout << "Nilai rata-rata " << nama_mhs[i] << " termasuk kategori 'A'" << endl;
        }
        else if (rata >= 70) {
            cout << "Nilai rata-rata " << nama_mhs[i] << " termasuk kategori 'B'" << endl;
        }
        else if (rata >= 60) {
            cout << "Nilai rata-rata " << nama_mhs[i] << " termasuk kategori 'C'" << endl;
        }
        else {
            cout << "Nilai rata-rata " << nama_mhs[i] << " termasuk kategori 'D'" << endl;
        }

        cout << "Nilai rata-rata: " << rata << endl;
        cout << "Nilai total: " << sum << endl;
        cout << "Nilai tertinggi: " << nilai_tertinggi << endl;
        cout << "Nilai terendah: " << nilai_terendah << "\n\n" << endl;



   

    }




    cin.get();
    return 0;
}
