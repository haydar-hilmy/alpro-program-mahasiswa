#include <iostream>
#include <string>
using namespace std;

class Design{
    public:
    void longLine(int N, string typeLine){
            for(int i = 0; i < N; i++){
                cout << typeLine;
        }
    }
    void getMargin(int N){
        for(int i = 0; i < N; i++){
            cout << " ";
        }
    }

    int checkNum(string N){
        for(int i = 0; i < N.length(); i++){
            if(!isdigit(N[i])){
                return false;
            }
        }
        return true;
    }

    string inputNum(int pjgMargin){
        string N;
        bool isTrue = false;
        Design design;

        while(!isTrue){
            cin >> N;
            if(!checkNum(N)){
                design.getMargin(pjgMargin); cout << "Yang anda masukkan bukan angka" << endl;
                design.getMargin(pjgMargin); cout << "Ulangi: "; 
            } else {
                isTrue = true;
            }
        }
        return N;
    }
};

class NamaSaya{
    private: // agar bisa dipakai hanya jika menggunakan class NamaSaya
        string nama, nim;
    public:
    NamaSaya(string nama, string nim){
        this->nama = nama;
        this->nim = nim;
    }
    void cetakNama(){
        cout << nama << endl;
    };
    void cetakNim(){
        cout << nim << endl;
    };
};

typedef struct data
{
    public:
        string nim, nama, kd_prodi, semester, alamat_pointer;
} Data;

void mainRunner(){

    NamaSaya nama("Haydar Hilmy Alhakim", "A11.2022.14577"); // deklarasi dengan constructor class nya NamaSaya
    Design design;

    // START IDENTITAS DIRI
    design.getMargin(5);    design.longLine(50, "="); cout << endl;
    design.getMargin(20);    nama.cetakNama();
    design.getMargin(23);    nama.cetakNim();
    design.getMargin(5);    design.longLine(50, "="); cout << endl;
    // END IDENTITAS DIRI

    // INPUT JUMLAH MAHASISWA USE ARRAY
    string inputjmlMhs;
    design.getMargin(8); cout << "Masukkan Jumlah Mahasiswa : ";
    int jmlMhs = stoi(design.inputNum(8)); // konversi dari angka string ke angka numerik int
    Data* mahasiswa = new Data[jmlMhs];

    // INPUT ARRAY MAHASISWA
    for(int i = 0; i < jmlMhs; i++){
        cout << endl;
        design.getMargin(8); cout << "Input Data Mahasiswa ke-" << i+1 << " || array-[" << i << "]" << endl;

        design.getMargin(12); cout << "Masukkan Nim       : ";
        cin.ignore();
        getline(cin, mahasiswa[i].nim);

        design.getMargin(12); cout << "Masukkan Nama Mhs  : ";
        
        getline(cin, mahasiswa[i].nama);

        design.getMargin(12); cout << "Masukkan Semester  : ";
        mahasiswa[i].semester = design.inputNum(12);

        design.getMargin(12); cout << "Masukkan kd. Prodi : ";
        cin >> mahasiswa[i].kd_prodi;
    }
    cout << endl;

    // OUTPUT ARRAY MAHASISWA
    int lenNim = 0;
    int lenNama = 0;
    int lenKdProdi = 0;

    for(int k = 0; k < jmlMhs; k++){
    if(mahasiswa[k].nim.length() > lenNim){
        lenNim = mahasiswa[k].nim.length();
    }
    if(mahasiswa[k].nama.length() > lenNama){
        lenNama = mahasiswa[k].nama.length();
    }
    if(mahasiswa[k].kd_prodi.length() > lenKdProdi){
        lenKdProdi = mahasiswa[k].kd_prodi.length();
    }
}

        design.getMargin(12); design.longLine(51 + lenNim + lenNama + lenKdProdi, "="); cout << endl;
    for(int i = 0; i < jmlMhs; i++){
        if(i == 0){
            design.getMargin(12);
            cout << "| NO ";
            cout << "| NIM ";
                design.getMargin(lenNim - 3);
            cout << "| Nama ";
                design.getMargin(lenNama);
            cout << "| Semester | Kd.Prodi | Alamat Pointer |";
            cout << endl;
        design.getMargin(12); design.longLine(51 + lenNim + lenNama + lenKdProdi, "=");
            cout << endl;
        }
        design.getMargin(12);

        // SAYA BUAT KOLOM LINE TABLE NYA MENJADI DINAMIS
        // kolom nomer
        cout << "| " << i+1;

        // kolom nim
        cout << "  | " << mahasiswa[i].nim;
        if(mahasiswa[i].nim.length() < lenNim){
            design.getMargin(lenNim - mahasiswa[i].nim.length());
        }

        // kolom nama
        cout << " | " << mahasiswa[i].nama;
        if(mahasiswa[i].nama.length() < lenNama){
            design.getMargin(lenNama - mahasiswa[i].nama.length());
        }

        // kolom semester
        cout << "     | " << mahasiswa[i].semester;
        if(mahasiswa[i].semester.length() >= 2){
            design.getMargin(1);
        }

        // kolom kdProdi
        cout << "        | " << mahasiswa[i].kd_prodi;
        if(mahasiswa[i].kd_prodi.length() < lenKdProdi){
            design.getMargin(lenKdProdi - mahasiswa[i].kd_prodi.length());
        }

        // kolom alamat pointer
        cout << "     | " << &mahasiswa[i] << "  |" << endl;
    }
        design.getMargin(12); design.longLine(51 + lenNim + lenNama + lenKdProdi, "="); cout << endl;

}

int main(){

    mainRunner();

    return 0;
}
