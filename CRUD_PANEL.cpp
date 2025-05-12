#include "CRUD_PANEL.h"

CRUD_PANEL::CRUD_PANEL(wxNotebook* parent)
    : wxPanel(parent, wxID_ANY) {

    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    wxButton* helloBtn = new wxButton(this, wxID_ANY, "Hallo");
    sizer->Add(helloBtn, 0, wxALL | wxCENTER, 10);
    SetSizerAndFit(sizer);

    helloBtn->Bind(wxEVT_BUTTON, &CRUD_PANEL::OnHelloClicked, this);
}

void CRUD_PANEL::OnHelloClicked(wxCommandEvent& event) {
    wxMessageBox("Halo dari Tab 1!", "Info", wxOK | wxICON_INFORMATION);
}
