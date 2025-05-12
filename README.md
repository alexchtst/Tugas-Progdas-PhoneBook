# Simple Phone Book Application
Aplikasi desktop sederhana berbasis **wxWidgets** yang memungkinkan pengguna untuk mengelola daftar kontak secara mudah. Melalui antarmuka tab yang intuitif, pengguna dapat menambahkan, mengubah, menghapus, dan melihat data kontak. Aplikasi ini juga mendukung fitur pemuatan data dari file CSV untuk mempercepat proses input data.

## Contributors
| Name | NIM | Email |
|-|-|-|
| Alex Cinatra Hutasoit | 22/505820/TK/55377 | alexcinatrahutasoit@mail.ugm.ac.id |
| Hansen Justin Handijaya || hansenjustinhandijaya@mail.ugm.ac.id |

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

