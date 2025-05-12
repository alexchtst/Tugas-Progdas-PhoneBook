/*
    load data dari file
*/

#include "LOAD_PANEL.h"

LOAD_PANEL::LOAD_PANEL(wxNotebook *parent)
    : wxPanel(parent, wxID_ANY)
{

    // sizer
    wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);

    // load csv button
    wxButton *loadBtn = new wxButton(this, wxID_ANY, "Muat dari File CSV");
    sizer->Add(loadBtn, 0, wxALL | wxCENTER, 5);
    loadBtn->Bind(wxEVT_BUTTON, &LOAD_PANEL::OnLoadCSV, this);
}

void LOAD_PANEL::LoadData()
{
    grid->SetCellValue(0, 0, "001");
    grid->SetCellValue(0, 1, "Alice");
    grid->SetCellValue(0, 2, "90");

    grid->SetCellValue(1, 0, "002");
    grid->SetCellValue(1, 1, "Bob");
    grid->SetCellValue(1, 2, "85");

    grid->SetCellValue(2, 0, "003");
    grid->SetCellValue(2, 1, "Charlie");
    grid->SetCellValue(2, 2, "78");
}

// open modal to csv file
void LOAD_PANEL::OnLoadCSV(wxCommandEvent &event)
{
    wxFileDialog openFileDialog(
        this, _("Pilih file CSV"), "", "",
        "CSV files (*.csv)|*.csv", wxFD_OPEN | wxFD_FILE_MUST_EXIST);

    if (openFileDialog.ShowModal() == wxID_CANCEL)
        return;

    // LoadCSVFile(openFileDialog.GetPath());
}