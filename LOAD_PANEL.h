/*
    load data dari file
*/

#ifndef LOAD_PANEL_H
#define LOAD_PANEL_H

#include <wx/wx.h>
#include <wx/notebook.h>
#include <wx/grid.h>

class LOAD_PANEL : public wxPanel {
public:
    LOAD_PANEL(wxNotebook* parent);

private:
    wxGrid* grid;
    void OnHelloClicked(wxCommandEvent& event);
    void LoadData();

    void OnLoadCSV(wxCommandEvent& event);
    void LoadCSVFile(const wxString& filepath);
};

#endif
