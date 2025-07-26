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

    // MainFrame.h - Adicione estas declarações à classe MainFrame

// IDs adicionais
enum {
    ID_ADD_EVOLUTION = wxID_HIGHEST + 1,
    ID_EDIT_EVOLUTION,
    ID_REMOVE_EVOLUTION,
    ID_ADD_MOVE,
    ID_EDIT_MOVE,
    ID_REMOVE_MOVE,
    ID_ADD_ATTACK,
    ID_EDIT_ATTACK,
    ID_REMOVE_ATTACK,
    ID_ADD_LOOT,
    ID_EDIT_LOOT,
    ID_REMOVE_LOOT,
    ID_ADD_VOICE,
    ID_EDIT_VOICE,
    ID_REMOVE_VOICE
};

    // Controles adicionais
    wxSpinCtrl* m_manacostCtrl;
    wxSpinCtrl* m_armorCtrl;
    wxSpinCtrl* m_moveMagicAttackBaseCtrl;
    wxSpinCtrl* m_moveMagicDefenseBaseCtrl;
    wxSpinCtrl* m_moveAttackBaseCtrl;
    wxListBox* m_attacksList;
    wxListBox* m_voicesList;

    // Controles para Look
    wxSpinCtrl* m_lookTypeCtrl;
    wxSpinCtrl* m_lookHeadCtrl;
    wxSpinCtrl* m_lookBodyCtrl;
    wxSpinCtrl* m_lookLegsCtrl;
    wxSpinCtrl* m_lookFeetCtrl;
    wxSpinCtrl* m_lookCorpseCtrl;

    // Controles para Flags
    wxCheckBox* m_summonableCtrl;
    wxCheckBox* m_attackableCtrl;
    wxCheckBox* m_hostileCtrl;
    wxCheckBox* m_passiveCtrl;

    // Controles
    wxTextCtrl* m_nameCtrl;
    wxTextCtrl* m_descCtrl;
    wxTextCtrl* m_raceCtrl;
    wxTextCtrl* m_race2Ctrl;
    wxSpinCtrl* m_expCtrl;
    wxSpinCtrl* m_dexIDCtrl;

    // Controles para Target Change
    wxSpinCtrl* m_targetChangeIntervalCtrl;
    wxSpinCtrl* m_targetChangeChanceCtrl;
    
    // Controles para Flags adicionais
    wxCheckBox* m_illusionableCtrl;
    wxCheckBox* m_convinceableCtrl;
    wxCheckBox* m_pushableCtrl;
    wxCheckBox* m_canpushitemsCtrl;
    wxCheckBox* m_canpushcreaturesCtrl;
    wxSpinCtrl* m_targetdistanceCtrl;
    wxSpinCtrl* m_staticattackCtrl;
    wxSpinCtrl* m_runonhealthCtrl;
    wxSpinCtrl* m_dexentryCtrl;
    wxSpinCtrl* m_portraitidCtrl;
    wxCheckBox* m_hasshinyCtrl;
    wxCheckBox* m_hasmegaCtrl;
    wxCheckBox* m_flyableCtrl;
    wxCheckBox* m_rideableCtrl;
    wxCheckBox* m_surfableCtrl;
    wxCheckBox* m_canteleportCtrl;
    wxSpinCtrl* m_catchchanceCtrl;
    
    // Controles para Level e Health
    wxSpinCtrl* m_minLevelCtrl;
    wxSpinCtrl* m_maxLevelCtrl;
    wxSpinCtrl* m_healthNowCtrl;
    wxSpinCtrl* m_healthMaxCtrl;
    
    // Stats
    wxSpinCtrl* m_speedCtrl;
    wxSpinCtrl* m_magicAttackCtrl;
    wxSpinCtrl* m_magicDefenseCtrl;
    wxSpinCtrl* m_attackBaseCtrl;
    wxSpinCtrl* m_meleeCtrl;
    wxSpinCtrl* m_defenseCtrl;
    
    // Listas
    wxListBox* m_evolutionsList;
    wxListBox* m_movesList;
    wxListBox* m_lootList;
    
    // Métodos para manipulação de dados
    void OnAddEvolution(wxCommandEvent& event);
    void OnEditEvolution(wxCommandEvent& event);
    void OnRemoveEvolution(wxCommandEvent& event);
    
    void OnAddMove(wxCommandEvent& event);
    void OnEditMove(wxCommandEvent& event);
    void OnRemoveMove(wxCommandEvent& event);
    
    void OnAddLoot(wxCommandEvent& event);
    void OnEditLoot(wxCommandEvent& event);
    void OnRemoveLoot(wxCommandEvent& event);
    
    void ShowEvolutionDialog(MonsterEvolution* evolution = nullptr);
    void ShowMoveDialog(MonsterMove* move = nullptr);
    void ShowLootDialog(MonsterLoot* loot = nullptr);

     // Métodos adicionais
    void CreateLookPage(wxWindow* parent);
    void CreateFlagsPage(wxWindow* parent);
    void CreateMovesPage(wxWindow* parent);
    void CreateTargetChangePage(wxWindow* parent);
    void CreateVoicesPage(wxWindow* parent);

    void ShowAttackDialog(MonsterAttack* attack = nullptr);
    void ShowVoiceDialog(MonsterData::Voice* voice = nullptr);

    void OnAddAttack(wxCommandEvent& event);
    void OnEditAttack(wxCommandEvent& event);
    void OnRemoveAttack(wxCommandEvent& event);
    void OnAddVoice(wxCommandEvent& event);
    void OnEditVoice(wxCommandEvent& event);
    void OnRemoveVoice(wxCommandEvent& event);

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