#ifndef CRUD_PANEL_H
#define CRUD_PANEL_H

#include <wx/wx.h>
#include <wx/notebook.h>

class CRUD_PANEL : public wxPanel {
public:
    CRUD_PANEL(wxNotebook* parent);

private:
    void OnHelloClicked(wxCommandEvent& event);
};

#endif
