#include "CRUD_PANEL.h"

CRUD_PANEL::CRUD_PANEL(wxNotebook* parent)
    : wxPanel(parent, wxID_ANY) {

    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);

    // Input fields
    nameCtrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(250, -1));
    addressCtrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(250, -1));
    phoneCtrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(250, -1));

    mainSizer->Add(new wxStaticText(this, wxID_ANY, "Nama:"), 0, wxLEFT | wxTOP, 10);
    mainSizer->Add(nameCtrl, 0, wxLEFT | wxBOTTOM, 10);
    mainSizer->Add(new wxStaticText(this, wxID_ANY, "Alamat:"), 0, wxLEFT, 10);
    mainSizer->Add(addressCtrl, 0, wxLEFT | wxBOTTOM, 10);
    mainSizer->Add(new wxStaticText(this, wxID_ANY, "Phone:"), 0, wxLEFT, 10);
    mainSizer->Add(phoneCtrl, 0, wxLEFT | wxBOTTOM, 10);

    // Buttons
    wxBoxSizer* btnSizer = new wxBoxSizer(wxHORIZONTAL);
    wxButton* addBtn = new wxButton(this, wxID_ANY, "Tambah");
    wxButton* editBtn = new wxButton(this, wxID_ANY, "Edit");
    wxButton* deleteBtn = new wxButton(this, wxID_ANY, "Hapus");

    btnSizer->Add(addBtn, 0, wxALL, 5);
    btnSizer->Add(editBtn, 0, wxALL, 5);
    btnSizer->Add(deleteBtn, 0, wxALL, 5);
    mainSizer->Add(btnSizer, 0, wxLEFT, 10);

    // ListCtrl
    listCtrl = new wxListCtrl(this, wxID_ANY, wxDefaultPosition, wxSize(500, 200),
                              wxLC_REPORT | wxLC_SINGLE_SEL);
    listCtrl->InsertColumn(0, "Nama", wxLIST_FORMAT_LEFT, 150);
    listCtrl->InsertColumn(1, "Alamat", wxLIST_FORMAT_LEFT, 200);
    listCtrl->InsertColumn(2, "Phone", wxLIST_FORMAT_LEFT, 120);
    mainSizer->Add(listCtrl, 0, wxALL, 10);

    SetSizer(mainSizer);

    // Events
    addBtn->Bind(wxEVT_BUTTON, &CRUD_PANEL::OnAdd, this);
    editBtn->Bind(wxEVT_BUTTON, &CRUD_PANEL::OnEdit, this);
    deleteBtn->Bind(wxEVT_BUTTON, &CRUD_PANEL::OnDelete, this);
    listCtrl->Bind(wxEVT_LIST_ITEM_SELECTED, &CRUD_PANEL::OnSelect, this);
}

void CRUD_PANEL::OnAdd(wxCommandEvent&) {
    wxString name = nameCtrl->GetValue();
    wxString addr = addressCtrl->GetValue();
    wxString phone = phoneCtrl->GetValue();

    if (name.IsEmpty() || addr.IsEmpty() || phone.IsEmpty()) {
        wxMessageBox("Isi semua kolom!", "Peringatan", wxICON_WARNING);
        return;
    }

    long index = listCtrl->InsertItem(listCtrl->GetItemCount(), name);
    listCtrl->SetItem(index, 1, addr);
    listCtrl->SetItem(index, 2, phone);

    nameCtrl->Clear();
    addressCtrl->Clear();
    phoneCtrl->Clear();
    selectedIndex = -1;
}

void CRUD_PANEL::OnEdit(wxCommandEvent&) {
    if (selectedIndex == -1) {
        wxMessageBox("Pilih item untuk diedit.", "Peringatan", wxICON_WARNING);
        return;
    }

    listCtrl->SetItem(selectedIndex, 0, nameCtrl->GetValue());
    listCtrl->SetItem(selectedIndex, 1, addressCtrl->GetValue());
    listCtrl->SetItem(selectedIndex, 2, phoneCtrl->GetValue());
}

void CRUD_PANEL::OnDelete(wxCommandEvent&) {
    if (selectedIndex == -1) {
        wxMessageBox("Pilih item untuk dihapus.", "Peringatan", wxICON_WARNING);
        return;
    }

    listCtrl->DeleteItem(selectedIndex);
    nameCtrl->Clear();
    addressCtrl->Clear();
    phoneCtrl->Clear();
    selectedIndex = -1;
}

void CRUD_PANEL::OnSelect(wxListEvent& event) {
    selectedIndex = event.GetIndex();
    nameCtrl->SetValue(listCtrl->GetItemText(selectedIndex));

    wxListItem addrItem;
    addrItem.SetId(selectedIndex);
    addrItem.SetColumn(1);
    addrItem.SetMask(wxLIST_MASK_TEXT);
    listCtrl->GetItem(addrItem);
    addressCtrl->SetValue(addrItem.GetText());

    wxListItem phoneItem;
    phoneItem.SetId(selectedIndex);
    phoneItem.SetColumn(2);
    phoneItem.SetMask(wxLIST_MASK_TEXT);
    listCtrl->GetItem(phoneItem);
    phoneCtrl->SetValue(phoneItem.GetText());
}
