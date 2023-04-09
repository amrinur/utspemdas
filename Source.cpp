/*
                     KELOMPOK 3
            Ahmad Jhiro 	(I0722007)
            Amri Nurfalah	(I0722008)
            Ardiya Adha F.	(I0722009)
*/



#include <iostream>
#include <cmath>        // libary untuk operasi matematika
#include <string>
#include <algorithm>    // libary untuk fungsi sort
#include <vector>       // libary untuk tipe data vector

using namespace std;

//untuk menyimpan informasi nama dan rata-rata nilai mahasiswa.
struct Mahasiswa
{
    string nama;
    double average;
};

//fungsi untuk membandingkan nilai rata-rata mahasiswa untuk digunakan pada fungsi sort.
bool compare(Mahasiswa a, Mahasiswa b)
{
    return (a.average > b.average);
}

int main()
{
    int bykmhs, bykmatkul;
    double  sum, nilaiterkecil = TMP_MAX, nilaimatkul, nilaitertinggi = -TMP_MAX;
    string nama, matkul;

    cout << "Masukkan Banyak Mahasiswa: ";
    cin >> bykmhs;
    cin.ignore(); //mengabaikan karakter pada input sebelumbnya

    // inisialisasi array Mahasiswa.
    Mahasiswa* mhs = new Mahasiswa[bykmhs]; 

    cout << "Masukkan Banyak Matkul: ";
    cin >> bykmatkul;
    cin.ignore();

   // agar namamatkul dapat menyimpan input mata kuliah dari user
    vector<string> namamatkul;

    // input mata kuliah
    for (int k = 0; k < bykmatkul; k++) {
        string matkul;
        cout << "Masukkan nama mata kuliah ke- " << k + 1 << ": ";
        getline(cin, matkul); //input nama mata kuliah
        namamatkul.push_back(matkul);
    }

    //input nama mahasiswa
    for (int j = 0; j < bykmhs; j++) {
        sum = 0;
        cout << "\n\t\tMasukkan Nama Mahasiswa ke " << j + 1 << " : ";
        getline(cin, mhs[j].nama); // input nama mahasiswa

        // input nilai
        for (int i = 0; i < bykmatkul; i++) {
            cout << "Nilai " << namamatkul[i] << " : ";
            cin >> nilaimatkul;
            cin.ignore();
            sum += nilaimatkul;
            mhs[j].average = sum / bykmatkul; //menghitung rata rata

            // mencari nilai terbesar dan terkecil
            if (nilaimatkul > nilaitertinggi) {
                nilaitertinggi = nilaimatkul;
            }
            if (nilaimatkul < nilaiterkecil) {
                nilaiterkecil = nilaimatkul;
            }

        }

        // hasil inputan
        cout << "Total Nilai " << mhs[j].nama << " : " << sum << endl;
        cout << "Rata Rata Nilai " << nama << " : " << mhs[j].average << endl;

        // output Grade nilai mahasiswa
        if (mhs[j].average >= 90) {
            cout << "Nilai rata-rata " << mhs[j].nama << " termasuk kategori 'A'" << endl;
        }
        else if (mhs[j].average >= 80) {
            cout << "Nilai rata-rata " << mhs[j].nama << " termasuk kategori 'B'" << endl;
        }
        else if (mhs[j].average >= 70) {
            cout << "Nilai rata-rata " << mhs[j].nama << " termasuk kategori 'C'" << endl;
        }
        else {
            cout << "Nilai rata-rata " << mhs[j].nama << " termasuk kategori 'D'" << endl;
        }

        // output max min nilai
        cout << "Nilai Terendah " << mhs[j].nama << " : " << nilaiterkecil << endl;
        cout << "Nilai Tertinggi " << mhs[j].nama << " : " << nilaitertinggi << endl;

    }

    // ranking
    sort(mhs, mhs + bykmhs, compare);
    cout << "\n\t  PERINGKAT MAHASISWA" << endl;
    cout << "Rank\t\tNama\t\t\tAverage\n";

    for (int j = 0; j < bykmhs; j++)
    {
        cout << j + 1 << "\t\t" << mhs[j].nama << "\t\t" << mhs[j].average << endl;
    }

    cin.get();
    return 0;

}