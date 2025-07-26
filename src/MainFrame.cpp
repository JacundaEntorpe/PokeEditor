#include "MainFrame.h"

// Adicione o evento table no in?cio do arquivo
wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_MENU(wxID_OPEN, MainFrame::OnOpen)
    EVT_MENU(wxID_SAVE, MainFrame::OnSave)
    EVT_MENU(wxID_EXIT, MainFrame::OnExit)
wxEND_EVENT_TABLE()

MainFrame::MainFrame(const wxString& title) 
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(800, 600)) {
    
    // Inicialize os ponteiros
    m_notebook = nullptr;
    m_nameCtrl = nullptr;
    m_expCtrl = nullptr;
    
    // Criar menu
    wxMenuBar* menuBar = new wxMenuBar;
    wxMenu* fileMenu = new wxMenu;
    fileMenu->Append(wxID_OPEN, "&Open\tCtrl-O");
    fileMenu->Append(wxID_SAVE, "&Save\tCtrl-S");
    fileMenu->AppendSeparator();
    fileMenu->Append(wxID_EXIT, "&Exit\tAlt-F4");
    menuBar->Append(fileMenu, "&File");
    SetMenuBar(menuBar);
    
    // Criar notebook (abas)
    m_notebook = new wxNotebook(this, wxID_ANY);
    
    // Adicionar p?ginas
    CreateGeneralInfoPage(m_notebook);
    CreateStatsPage(m_notebook);
    CreateEvolutionsPage(m_notebook);
    CreateAttacksPage(m_notebook);
    CreateLootPage(m_notebook);
    
    // Centralizar e mostrar
    Centre();
}

void MainFrame::CreateGeneralInfoPage(wxWindow* parent) {
    wxPanel* panel = new wxPanel(parent);
    wxFlexGridSizer* sizer = new wxFlexGridSizer(2, 5, 5);
    
    // Nome
    sizer->Add(new wxStaticText(panel, wxID_ANY, "Name:"), 0, wxALIGN_CENTER_VERTICAL);
    m_nameCtrl = new wxTextCtrl(panel, wxID_ANY);
    sizer->Add(m_nameCtrl, 1, wxEXPAND);
    
    // Experi?ncia
    sizer->Add(new wxStaticText(panel, wxID_ANY, "Experience:"), 0, wxALIGN_CENTER_VERTICAL);
    m_expCtrl = new wxSpinCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 1000000, 0);
    sizer->Add(m_expCtrl, 1, wxEXPAND);
    
    // Configurar o sizer
    sizer->AddGrowableCol(1, 1);
    panel->SetSizer(sizer);
    
    // Corrigido: usar AddPage do wxNotebook
    wxNotebook* notebook = wxDynamicCast(parent, wxNotebook);
    if (notebook) {
        notebook->AddPage(panel, "General Info");
    }
}

void MainFrame::OnOpen(wxCommandEvent& event) {
    wxFileDialog openFileDialog(this, "Open Monster XML", "", "", 
                              "XML files (*.xml)|*.xml", wxFD_OPEN|wxFD_FILE_MUST_EXIST);
    
    if (openFileDialog.ShowModal() == wxID_CANCEL) return;
    
    if (m_monsterData.LoadFromXML(openFileDialog.GetPath())) {
        // Atualizar controles com os dados carregados
        m_nameCtrl->SetValue(m_monsterData.name);
        m_expCtrl->SetValue(m_monsterData.experience);
        // Atualizar outros controles...
    } else {
        wxMessageBox("Failed to load XML file", "Error", wxOK | wxICON_ERROR);
    }
}

void MainFrame::OnSave(wxCommandEvent& event) {
    // Atualizar dados na mem?ria a partir dos controles
    m_monsterData.name = m_nameCtrl->GetValue();
    m_monsterData.experience = m_expCtrl->GetValue();
    // Atualizar outros campos...
    
    wxFileDialog saveFileDialog(this, "Save Monster XML", "", "", 
                              "XML files (*.xml)|*.xml", wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
    
    if (saveFileDialog.ShowModal() == wxID_CANCEL) return;
    
    if (!m_monsterData.SaveToXML(saveFileDialog.GetPath())) {
        wxMessageBox("Failed to save XML file", "Error", wxOK | wxICON_ERROR);
    }
}

void MainFrame::CreateStatsPage(wxWindow* parent) {
    // TODO: Implemente esta aba depois
    wxPanel* panel = new wxPanel(parent);
    wxNotebook* notebook = wxDynamicCast(parent, wxNotebook);
    if (notebook) {
        notebook->AddPage(panel, "Stats");
    }
}

void MainFrame::CreateEvolutionsPage(wxWindow* parent) {
    wxPanel* panel = new wxPanel(parent);
    wxNotebook* notebook = wxDynamicCast(parent, wxNotebook);
    if (notebook) {
        notebook->AddPage(panel, "Evolutions");
    }
}

void MainFrame::CreateAttacksPage(wxWindow* parent) {
    wxPanel* panel = new wxPanel(parent);
    wxNotebook* notebook = wxDynamicCast(parent, wxNotebook);
    if (notebook) {
        notebook->AddPage(panel, "Attacks");
    }
}

void MainFrame::CreateLootPage(wxWindow* parent) {
    wxPanel* panel = new wxPanel(parent);
    wxNotebook* notebook = wxDynamicCast(parent, wxNotebook);
    if (notebook) {
        notebook->AddPage(panel, "Loot");
    }
}

void MainFrame::OnExit(wxCommandEvent& event) {
    Close(true);
}