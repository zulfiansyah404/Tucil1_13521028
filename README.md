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
Program untuk mencari semua kemungkinan operasi dari empat bilangan untuk menghasilkan nilai 24. Terdapat dua opsi input pada program, yaitu input manual dan input random. Untuk input manual, program akan meminta empat input string. Input harus salah satu dari {'A', '2', '3', ..., 'J', 'Q', 'K'}. Jika input tidak sesuai maka program akan meminta ulang input. Lalu program akan mencari semua kemungkinan jawaban yang mungkin. Di akhir program akan diminta apakah user ingin menyimpan jawaban atau tidak.

## Struktur Program
```bash
.
│   README.md
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
        jawaban.txt
```

## Requirement Program
* Java Virtual Machine versi 11 atau lebih baru.

## Cara Kompilasi Program
1. Pastikan Java Virtual Machine versi 11 atau lebih baru sudah terpasang pada mesin eksekusi (Anda dapat mengecek versi Java Virtual Machine dengan menjalan command `java -version` pada command prompt).
2. Jalankan command `./extract` atau `./extract.bat` pada command prompt jika Anda menggunakan Windows dan jalankan command `./extract.sh` pada command prompt jika Anda menggunakan Linux atau macOS.
3. Jika berhasil dikompilasi, maka akan terdapat folder `bin` pada directory program.

## Cara Menjalankan Program
1. Pastikan Anda telah berhasil melakukan kompilasi pada program.
2. Tambahkan file teks dalam format `.txt` yang berisi matriks huruf di dalam *puzzle* (antarhuruf dipisahkan oleh spasi), diikuti satu baris kosong, dan daftar kata-kata yang akan dicari di dalam *puzzle* ke dalam folder `test` pada directory program.
3. Jalankan command `./run` atau `./run.bat` pada command prompt jika Anda menggunakan Windows dan jalankan command `./run.sh` pada command prompt jika Anda menggunakan Linux atau macOS.
4. Masukkan nama file teks yang sudah ditambahkan sebelumnya ke dalam input program.

## Author
* Nama: Rayhan Kinan Muhannad
* NIM: 13520065
* Prodi/Jurusan: STEI/Teknik Informatika
* Profile Github: [rayhankinan](https://github.com/rayhankinan)