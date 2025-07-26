#include <wx/wx.h>
#include <wx/notebook.h>
#include <wx/spinctrl.h>
#include "MonsterData.h"

class MainFrame : public wxFrame {
public:
    MainFrame(const wxString& title);
    
    void LoadMonsterData(const wxString& filename);
    void SaveMonsterData(const wxString& filename);
    
private:
    MonsterData m_monsterData;
    wxNotebook* m_notebook;
    
    // Adicione estas declara??es de controles
    wxTextCtrl* m_nameCtrl;
    wxSpinCtrl* m_expCtrl;
    // Adicione outros controles conforme necess?rio
    
    void CreateGeneralInfoPage(wxWindow* parent);
    void CreateStatsPage(wxWindow* parent);
    void CreateEvolutionsPage(wxWindow* parent);
    void CreateAttacksPage(wxWindow* parent);
    void CreateLootPage(wxWindow* parent);
    
    void OnOpen(wxCommandEvent& event);
    void OnSave(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    
    wxDECLARE_EVENT_TABLE();
};