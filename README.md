# Penyelesaian Permainan Kartu 24 dengan Algoritma Brute Force
Disusun untuk memenuhi Tugas Kecil 1 IF2211 Strategi Algoritma "Penyelesaian *Permainan Kartu 24* dengan *Algoritma Brute Force*".

## Daftar Isi
* [Deskripsi Singkat Program](#deskripsi-singkat-program)
* [Struktur Program](#struktur-program)
* [Requirement Program](#struktur-program)
* [Cara Kompilasi Program](#cara-kompilasi-program)
* [Cara Menjalankan Program](#cara-menjalankan-program)
* [Author](#author)

## Deskripsi Singkat Program
Program untuk mencari semua kemungkinan operasi dari empat bilangan untuk menghasilkan nilai 24. Terdapat dua opsi input pada program, yaitu input manual dan input random. Untuk input manual, program akan meminta empat input string.
## Struktur Program
```bash
.
│   README.md
├───.vscode
│       c_cpp_properties.json
│       settings.json
│       tasks.json
│
├───bin
│       main.exe
│
├───doc
│       Tucil1_K3_13521028_Muhammad Zulfiansyah Bayu Pratama.pdf
│       
├───src
│       bilangan.h
│       bruteforce.h
│       fitur.h
│       main.cpp
│       splash.h
│
└───test
        answer_2_4_6_8_.txt
        answer_3_8_4_7_.txt
        answer_10_J_Q_K_.txt
        answer_A_2_3_4_.txt
        answer_A_2_6_7_.txt
        answer_A_8_9_Q_.txt
```

## Requirement Program
* C/C++ Compiler (Minimal MINGW G++ 12.1.0)

## Cara Kompilasi Program
1. Pastikan C/C++ Compiler sudah terpasang pada mesin eksekusi (Anda dapat mengecek versi C/C++ Compiler dengan menjalan command `g++ --version` pada command prompt).
2. Kompilasi program pada "src/main.cpp" dengan menggunakan tombol kompilasi pada masing-masing code editor atau dengan menjalankan command `g++ src\main.cpp -o bin\main.exe` (Usahakan memakai tombol 'Run' pada VS Code agar Splashscreen terlihat lebih jelas)
3. Jika berhasil dikompilasi, maka akan terdapat folder `bin` pada directory program.

## Cara Menjalankan Program
1. Pastikan Anda telah berhasil melakukan kompilasi pada program.
2. Saat program berhasil dijalankan, anda akan diminta apakah program menerim input manual dari user atau dipilih secara random oleh program. Ikuti instruksi dari program. 
3. Jika anda memilih input manual, maka anda akan diminta memasukkan 4 buah string dari salah satu {'A', '2', '3', ..., 'J', 'Q', 'K'}. Jika tidak sesuai maka program akan meminta ulang input.
4. Setelah program berhasil menemukan solusi, user akan diminta input apakah user ingin menyimpan hasil solusi dalam bentuk file txt. Tekan `y` untuk mengeksport output program.

## Author
* Nama: Muhammad Zulfiansyah Bayu Pratama
* NIM: 13521028
* Prodi/Jurusan: STEI/Teknik Informatika
* Profile Github: [zulfiansyah404](https://github.com/zulfiansyah404)