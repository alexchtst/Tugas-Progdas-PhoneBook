/*
    load data dari file
*/

#ifndef LOAD_PANEL_H
#define LOAD_PANEL_H

#include <wx/wx.h>
#include <wx/notebook.h>
#include <wx/grid.h>

class LOAD_PANEL : public wxPanel
{
public:
    LOAD_PANEL(wxNotebook *parent);

private:
    wxGrid *grid = nullptr;
    wxButton *loadBtn;
    wxBoxSizer *mainSizer;
    wxBoxSizer *buttonSizer;
    bool fileLoaded;

    void OnLoadCSV(wxCommandEvent &event);
    void LoadCSVFile(const wxString &filepath);
    void UpdateButtonPosition();
};

#endif
