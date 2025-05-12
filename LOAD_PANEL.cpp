/*
    load data dari file
*/

#include "LOAD_PANEL.h"
#include <wx/textfile.h>
#include <wx/filedlg.h>
#include <wx/tokenzr.h>

#include <wx/filedlg.h>
#include <wx/textfile.h>
#include <wx/tokenzr.h>

LOAD_PANEL::LOAD_PANEL(wxNotebook *parent)
    : wxPanel(parent, wxID_ANY), fileLoaded(false)
{
    // Sizer utama
    const wxString *tempFilePath = nullptr;

    mainSizer = new wxBoxSizer(wxVERTICAL);

    // Tambah judul
    wxStaticText *title = new wxStaticText(this, wxID_ANY, "FILE LOAD", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER);
    title->SetFont(wxFont(14, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    mainSizer->Add(title, 0, wxALL | wxALIGN_CENTER, 10);

    // Panel tombol, supaya bisa diganti posisi
    buttonSizer = new wxBoxSizer(wxHORIZONTAL);
    loadBtn = new wxButton(this, wxID_ANY, "Load file csv");
    buttonSizer->Add(loadBtn, 0, wxALL, 5);
    mainSizer->Add(buttonSizer, 0, wxALIGN_CENTER); // tombol awal di tengah

    loadBtn->Bind(wxEVT_BUTTON, &LOAD_PANEL::OnLoadCSV, this);

    SetSizer(mainSizer);
}

// open modal to csv file
void LOAD_PANEL::OnLoadCSV(wxCommandEvent &event)
{
    wxFileDialog openFileDialog(
        this, _("Pilih file CSV"), "", "",
        "CSV files (*.csv)|*.csv", wxFD_OPEN | wxFD_FILE_MUST_EXIST);

    if (openFileDialog.ShowModal() == wxID_CANCEL)
        return;

    LoadCSVFile(openFileDialog.GetPath());
}

void LOAD_PANEL::LoadCSVFile(const wxString &filepath)
{
    wxTextFile file;
    if (!file.Open(filepath)) {
        wxMessageBox("Gagal membuka file!", "Error", wxICON_ERROR);
        return;
    }

    wxArrayString lines;
    for (wxString str = file.GetFirstLine(); !file.Eof(); str = file.GetNextLine())
        lines.Add(str);
    file.Close();

    if (lines.IsEmpty()) {
        wxMessageBox("File kosong atau tidak valid.", "Peringatan", wxICON_WARNING);
        return;
    }

    wxArrayString headers = wxSplit(lines[0], ',');
    size_t numCols = headers.GetCount();
    size_t numRows = lines.GetCount() - 1;

    // Hapus grid lama jika ada
    if (grid) {
        mainSizer->Detach(grid);
        grid->Destroy();
        grid = nullptr;
    }

    // Buat grid baru
    grid = new wxGrid(this, wxID_ANY);
    grid->CreateGrid(numRows, numCols);
    grid->DisableDragColSize();
    grid->DisableDragRowSize();
    mainSizer->Add(grid, 1, wxEXPAND | wxALL, 10);

    // Set header kolom
    for (size_t c = 0; c < numCols; ++c)
        grid->SetColLabelValue(c, headers[c]);

    // Set isi sel
    for (size_t r = 1; r < lines.GetCount(); ++r) {
        wxArrayString rowData = wxSplit(lines[r], ',');
        for (size_t c = 0; c < rowData.GetCount() && c < numCols; ++c)
            grid->SetCellValue(r - 1, c, rowData[c]);
    }

    fileLoaded = true;
    UpdateButtonPosition();
    Layout();
}

void LOAD_PANEL::UpdateButtonPosition()
{
    if (!fileLoaded)
        return;

    mainSizer->Detach(buttonSizer);

    mainSizer->Add(buttonSizer, 0, wxALIGN_RIGHT | wxALL, 10);

    Layout();
}
