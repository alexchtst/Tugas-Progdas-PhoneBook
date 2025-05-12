#include <wx/wx.h>
#include <wx/notebook.h>
#include "CRUD_PANEL.h"
#include "LOAD_PANEL.h"

class MyFrame : public wxFrame {
public:
    MyFrame();
};

class MyApp : public wxApp {
public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {
    MyFrame* frame = new MyFrame();
    frame->Show(true);
    return true;
}

MyFrame::MyFrame()
    : wxFrame(NULL, wxID_ANY, "Aplikasi dengan Tab", wxDefaultPosition, wxSize(1080, 600)) {

    SetBackgroundColour(*wxWHITE);

    wxNotebook* notebook = new wxNotebook(this, wxID_ANY);

    // Menambahkan panel ke tab
    notebook->AddPage(new CRUD_PANEL(notebook), "CRUD Panel");
    notebook->AddPage(new LOAD_PANEL(notebook), "Load Panel");
}
