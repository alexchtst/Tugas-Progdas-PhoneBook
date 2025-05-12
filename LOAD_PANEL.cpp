/*
    load data dari file
*/

#include "LOAD_PANEL.h"
#include <wx/textfile.h>
#include <wx/filedlg.h>
#include <wx/tokenzr.h>

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

void LOAD_PANEL::LoadCSVFile(const wxString &filepath)
{
    wxTextFile file;

    // file not found exception
    if (!file.Open(filepath))
    {
        wxMessageBox("Gagal membuka file!", "Error", wxICON_ERROR);
        return;
    }

    // read file and buffer it
    wxArrayString lines;
    for (wxString str = file.GetFirstLine(); !file.Eof(); str = file.GetNextLine())
        lines.Add(str);

    file.Close();

    // empty csv file handling
    if (lines.IsEmpty())
        return;
    
    
    // write every fucking data in grid
    grid->ClearGrid();
    if (grid->GetNumberRows() > 0)
        grid->DeleteRows(0, grid->GetNumberRows());
    if (grid->GetNumberCols() > 0)
        grid->DeleteCols(0, grid->GetNumberCols());

    wxArrayString headers = wxSplit(lines[0], ',');
    grid->AppendCols(headers.GetCount());
    for (size_t c = 0; c < headers.GetCount(); ++c)
        grid->SetColLabelValue(c, headers[c]);

    for (size_t r = 1; r < lines.GetCount(); ++r)
    {
        wxArrayString rowData = wxSplit(lines[r], ',');
        grid->AppendRows(1);
        for (size_t c = 0; c < rowData.GetCount(); ++c)
            grid->SetCellValue(r - 1, c, rowData[c]);
    }
}