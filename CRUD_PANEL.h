#ifndef CRUD_PANEL_H
#define CRUD_PANEL_H

#include <wx/wx.h>
#include <wx/listctrl.h>
#include <wx/notebook.h>
#include <wx/grid.h>


class CRUD_PANEL : public wxPanel {
public:
    CRUD_PANEL(wxNotebook* parent);

private:
    wxTextCtrl* nameCtrl;
    wxTextCtrl* addressCtrl;
    wxTextCtrl* phoneCtrl;
    wxListCtrl* listCtrl;

    void OnAdd(wxCommandEvent& event);
    void OnEdit(wxCommandEvent& event);
    void OnDelete(wxCommandEvent& event);
    void OnSelect(wxListEvent& event);

    long selectedIndex = -1;  // Track selected item
};

#endif
