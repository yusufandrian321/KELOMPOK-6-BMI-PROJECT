#include <iostream>
#include <iomanip>
#include <fstream> // Untuk file handling
using namespace std;

int main() {
    float berat_badan, tinggi_badan_cm, tinggi_badan_m, BMI;
    string keterangan;

    cout << "\t" << "BMI CALCULATOR" << endl;
    cout << "--------------------------" << endl;

    cout << " " << endl;
    cout << "   BMI" << "\t\t" << "Keterangan" << endl;
    cout << "-----------" << "\t" << "---------------------------" << endl;
    cout << " <18.5" << "\t\t" << "Kekurangan berat badan" << endl;
    cout << " 18.5 - <25" << "\t" << "Ideal" << endl;
    cout << " 25 - <30" << "\t" << "Kelebihan berat badan" << endl;
    cout << " >=30" << "\t\t" << "Obesitas" << endl;
    cout << "----------------------------" << endl;
    cout << " " << endl;

    cout << "Input berat badan (kg): ";
    cin >> berat_badan;
    cout << "Input tinggi badan (cm): ";
    cin >> tinggi_badan_cm;
    cout << "----------------------------" << endl;

    tinggi_badan_m = tinggi_badan_cm / 100;
    BMI = berat_badan / (tinggi_badan_m * tinggi_badan_m);

    if (BMI < 18.5) {
        keterangan = "Kekurangan berat badan";
    } else if (BMI >= 18.5 && BMI < 25) {
        keterangan = "Ideal";
    } else if (BMI >= 25 && BMI < 30) {
        keterangan = "Kelebihan berat badan";
    } else if (BMI >= 30) {
        keterangan = "Obesitas";
    } else {
        keterangan = "Input tidak valid";
    }

    // Menampilkan hasil di layar
    cout << " " << endl;
    cout << "Berat Badan " << "\t: " << berat_badan << " kg" << endl;
    cout << "Tinggi Badan" << "\t: " << tinggi_badan_cm << " cm" << endl;
    cout << "BMI" << "\t\t: " << fixed << setprecision(2) << BMI << endl;
    cout << "Keterangan BMI" << "\t: " << keterangan << endl;

    // Menulis hasil ke file CSV
    ofstream file_output("hasil_bmi.csv", ios::app); // Membuka file untuk menambahkan data
    if (file_output.is_open()) {
        file_output << berat_badan << ","
                    << tinggi_badan_cm << ","
                    << fixed << setprecision(2) << BMI << ","
                    << keterangan << endl;
        file_output.close();
        cout << "Hasil telah disimpan ke 'hasil_bmi.csv'" << endl;
    } else {
        cerr << "Gagal membuka file untuk menulis data." << endl;
    }

    return 0;
}
