# Simple Phone Book Application
Aplikasi desktop sederhana berbasis **wxWidgets** yang memungkinkan pengguna untuk mengelola daftar kontak secara mudah. Melalui antarmuka tab yang intuitif, pengguna dapat menambahkan, mengubah, menghapus, dan melihat data kontak. Aplikasi ini juga mendukung fitur pemuatan data dari file CSV untuk mempercepat proses input data.

## Contributors
| Name | NIM | Email |
|-|-|-|
| Alex Cinatra Hutasoit | 22/505820/TK/55377 | alexcinatrahutasoit@mail.ugm.ac.id |
| Hansen Justin Handijaya | 22/493030/TK/53980 | hansenjustinhandijaya@mail.ugm.ac.id |

## OOP Implementation

Aplikasi ini dibangun menggunakan pendekatan **Object-Oriented Programming (OOP)** dengan library **wxWidgets**, dan menerapkan beberapa pilar utama OOP, yaitu:

---

### 🧬 1. Inheritance (Pewarisan)

Inheritance digunakan untuk membangun **antarmuka utama (frame)** dan **panel-panel** aplikasi dengan cara menurunkan kelas-kelas dari komponen wxWidgets:

* `MyFrame` mewarisi dari `wxFrame`, menjadi jendela utama aplikasi.
* `CRUD_PANEL` dan `LOAD_PANEL` mewarisi dari `wxPanel`, yang memungkinkan mereka digunakan sebagai tab (halaman) di dalam `wxNotebook`.

Dengan pewarisan ini, masing-masing panel mendapatkan semua fitur dasar dari `wxPanel`, dan dapat menambahkan fungsionalitas sesuai kebutuhan spesifik.

### 🔒 2. Encapsulation (Enkapsulasi)

Encapsulation diterapkan dengan **menyembunyikan detail implementasi** dan menjaga **data internal tetap terlindungi** dari luar kelas:

* Variabel seperti `selectedIndex` pada `CRUD_PANEL` hanya dapat diakses dan dimodifikasi melalui fungsi anggota (misalnya saat memilih dan mengedit item).
* Objek-objek GUI seperti `nameCtrl`, `grid`, `listCtrl`, dan `mainSizer` adalah anggota privat dari kelas panel, tidak diakses langsung dari luar.
* Fungsi seperti `LoadCSVFile()` dan `UpdateButtonPosition()` bersifat internal untuk `LOAD_PANEL`, dan tidak diekspos ke luar.

### 🎭 3. Abstraction (Abstraksi)

Abstraksi dicapai dengan **memisahkan antarmuka pengguna dari logika internal**:

* Pengguna cukup menekan tombol dan melihat hasil (misalnya menambah atau memuat data), tanpa mengetahui cara penyimpanan, pemrosesan teks, atau pembentukan grid/list.
* Kelas `CRUD_PANEL` dan `LOAD_PANEL` menyederhanakan interaksi pengguna ke dalam fungsi spesifik seperti `OnAdd`, `OnEdit`, `OnLoadCSV`, dan `UpdateButtonPosition`.

**modular dan mudah dimengerti**

### 🔁 4. Polymorphism (Polimorfisme)

Polimorfisme dalam bentuk eksplisit tidak terlalu dominan di aplikasi ini, namun konsepnya tetap hadir secara **implisit melalui pewarisan wxWidgets**:

* Semua komponen panel (`wxPanel`) bisa diperlakukan sebagai objek dari superclass `wxWindow` oleh wxWidgets.
* `wxNotebook->AddPage(...)` menerima argumen bertipe `wxWindow*`, sehingga dapat menampung objek dari kelas turunan manapun seperti `CRUD_PANEL` atau `LOAD_PANEL`.

`wxNotebook` hanya tahu bahwa itu adalah `wxWindow`, namun tetap bisa menangani berbagai jenis panel, merupakan implementasi dari **polimorfisme dinamis (runtime polymorphism)**.

## Deskripsi

Aplikasi ini dirancang untuk memenuhi kebutuhan dasar dalam pengelolaan data kontak seperti nama, alamat, dan nomor telepon. Terdapat dua tab utama dalam aplikasi:

1. **Tab CRUD (Create, Read, Update, Delete)**  
   Pada tab ini, pengguna dapat:
   - Menambahkan data kontak baru.
   - Memilih data yang sudah ada untuk diedit.
   - Menghapus kontak dari daftar.
   - Melihat daftar kontak dalam format tabel (`wxListCtrl`).

2. **Tab Load CSV**  
   Tab ini memungkinkan pengguna untuk:
   - Memuat file CSV yang berisi data kontak.
   - Menampilkan data dari file tersebut dalam tabel (`wxGrid`).
   - Memastikan format file yang di-load sesuai agar data ditampilkan dengan benar.

Setiap perubahan pada data secara otomatis diperbarui di tampilan tabel, dan input pengguna divalidasi untuk mencegah data kosong.

## Features

- 📝 **Add Contact**: Tambahkan data kontak baru (Nama, Alamat, dan Nomor Telepon) ke dalam daftar.
- ✏️ **Edit Contact**: Pilih dan ubah informasi kontak yang sudah ada.
- ❌ **Delete Contact**: Hapus kontak yang dipilih dari daftar.
- 📄 **View Contact List**: Tampilkan daftar kontak dalam bentuk tabel menggunakan `wxListCtrl`.
- 💾 **Save to CSV (opsional)**: Simpan semua data kontak ke dalam file `.csv` untuk backup atau ekspor (dapat ditambahkan).
- 🖥️ **User Interface**: Aplikasi menggunakan antarmuka grafis berbasis `wxWidgets` dengan tab untuk navigasi.


## Techstack

- Bahasa Pemrograman: **C++17**
- Library GUI: **wxWidgets 3.2+**
- Sistem Build: **CMake**
- Platform: **Cross-platform (Windows, Linux, macOS)**
