#include "MainFrame.h"
#include <wx/filedlg.h>
#include <wx/msgdlg.h>

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_MENU(wxID_OPEN, MainFrame::OnOpen)
    EVT_MENU(wxID_SAVE, MainFrame::OnSave)
    EVT_MENU(wxID_EXIT, MainFrame::OnExit)
    
    EVT_BUTTON(ID_ADD_MOVE, MainFrame::OnAddMove)
    EVT_BUTTON(ID_EDIT_MOVE, MainFrame::OnEditMove)
    EVT_BUTTON(ID_REMOVE_MOVE, MainFrame::OnRemoveMove)
    
    EVT_BUTTON(ID_ADD_ATTACK, MainFrame::OnAddAttack)
    EVT_BUTTON(ID_EDIT_ATTACK, MainFrame::OnEditAttack)
    EVT_BUTTON(ID_REMOVE_ATTACK, MainFrame::OnRemoveAttack)
    
    EVT_BUTTON(ID_ADD_EVOLUTION, MainFrame::OnAddEvolution)
    EVT_BUTTON(ID_EDIT_EVOLUTION, MainFrame::OnEditEvolution)
    EVT_BUTTON(ID_REMOVE_EVOLUTION, MainFrame::OnRemoveEvolution)
    
    EVT_BUTTON(ID_ADD_LOOT, MainFrame::OnAddLoot)
    EVT_BUTTON(ID_EDIT_LOOT, MainFrame::OnEditLoot)
    EVT_BUTTON(ID_REMOVE_LOOT, MainFrame::OnRemoveLoot)
    
    EVT_BUTTON(ID_ADD_VOICE, MainFrame::OnAddVoice)
    EVT_BUTTON(ID_EDIT_VOICE, MainFrame::OnEditVoice)
    EVT_BUTTON(ID_REMOVE_VOICE, MainFrame::OnRemoveVoice)
wxEND_EVENT_TABLE()

MainFrame::MainFrame(const wxString& title) 
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(1000, 700)) {
    
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
    
    // Adicionar páginas
    CreateGeneralInfoPage(m_notebook);
    CreateStatsPage(m_notebook);
    CreateLookPage(m_notebook);
    CreateFlagsPage(m_notebook);
    CreateMovesPage(m_notebook);
    CreateTargetChangePage(m_notebook);
    CreateAttacksPage(m_notebook);
    CreateEvolutionsPage(m_notebook);
    CreateLootPage(m_notebook);
    CreateVoicesPage(m_notebook);
    
    // Centralizar e mostrar
    Centre();
}

// Implementação das funções de criação de páginas e diálogos
// (Devido ao tamanho, vou mostrar apenas algumas como exemplo)

void MainFrame::CreateGeneralInfoPage(wxWindow* parent) {
    wxPanel* panel = new wxPanel(parent);
    wxFlexGridSizer* sizer = new wxFlexGridSizer(2, 5, 5);
    
    // Nome
    sizer->Add(new wxStaticText(panel, wxID_ANY, "Name:"), 0, wxALIGN_CENTER_VERTICAL);
    m_nameCtrl = new wxTextCtrl(panel, wxID_ANY);
    sizer->Add(m_nameCtrl, 1, wxEXPAND);
    
    // Descrição
    sizer->Add(new wxStaticText(panel, wxID_ANY, "Description:"), 0, wxALIGN_CENTER_VERTICAL);
    m_descCtrl = new wxTextCtrl(panel, wxID_ANY);
    sizer->Add(m_descCtrl, 1, wxEXPAND);
    
    // Raça
    sizer->Add(new wxStaticText(panel, wxID_ANY, "Race:"), 0, wxALIGN_CENTER_VERTICAL);
    m_raceCtrl = new wxTextCtrl(panel, wxID_ANY);
    sizer->Add(m_raceCtrl, 1, wxEXPAND);
    
    // Raça 2
    sizer->Add(new wxStaticText(panel, wxID_ANY, "Secondary Race:"), 0, wxALIGN_CENTER_VERTICAL);
    m_race2Ctrl = new wxTextCtrl(panel, wxID_ANY);
    sizer->Add(m_race2Ctrl, 1, wxEXPAND);
    
    // Experiência
    sizer->Add(new wxStaticText(panel, wxID_ANY, "Experience:"), 0, wxALIGN_CENTER_VERTICAL);
    m_expCtrl = new wxSpinCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 1000000, 0);
    sizer->Add(m_expCtrl, 1, wxEXPAND);
    
    // Speed
    sizer->Add(new wxStaticText(panel, wxID_ANY, "Speed:"), 0, wxALIGN_CENTER_VERTICAL);
    m_speedCtrl = new wxSpinCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 1000, 0);
    sizer->Add(m_speedCtrl, 1, wxEXPAND);
    
    // Manacost
    sizer->Add(new wxStaticText(panel, wxID_ANY, "Manacost:"), 0, wxALIGN_CENTER_VERTICAL);
    m_manacostCtrl = new wxSpinCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 1000, 0);
    sizer->Add(m_manacostCtrl, 1, wxEXPAND);
    
    sizer->AddGrowableCol(1, 1);
    panel->SetSizer(sizer);
    
    wxNotebook* notebook = wxDynamicCast(parent, wxNotebook);
    if (notebook) {
        notebook->AddPage(panel, "General Info");
    }
}

void MainFrame::CreateStatsPage(wxWindow* parent) {
    wxPanel* panel = new wxPanel(parent);
    wxFlexGridSizer* sizer = new wxFlexGridSizer(2, 5, 5);
    
    // Armor
    sizer->Add(new wxStaticText(panel, wxID_ANY, "Armor:"), 0, wxALIGN_CENTER_VERTICAL);
    m_armorCtrl = new wxSpinCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 1000, 0);
    sizer->Add(m_armorCtrl, 1, wxEXPAND);
    
    // Defense
    sizer->Add(new wxStaticText(panel, wxID_ANY, "Defense:"), 0, wxALIGN_CENTER_VERTICAL);
    m_defenseCtrl = new wxSpinCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 1000, 0);
    sizer->Add(m_defenseCtrl, 1, wxEXPAND);
    
    // Magic Attack Base
    sizer->Add(new wxStaticText(panel, wxID_ANY, "Magic Attack:"), 0, wxALIGN_CENTER_VERTICAL);
    m_moveMagicAttackBaseCtrl = new wxSpinCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 1000, 0);
    sizer->Add(m_moveMagicAttackBaseCtrl, 1, wxEXPAND);
    
    // Magic Defense Base
    sizer->Add(new wxStaticText(panel, wxID_ANY, "Magic Defense:"), 0, wxALIGN_CENTER_VERTICAL);
    m_moveMagicDefenseBaseCtrl = new wxSpinCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 1000, 0);
    sizer->Add(m_moveMagicDefenseBaseCtrl, 1, wxEXPAND);
    
    // Attack Base
    sizer->Add(new wxStaticText(panel, wxID_ANY, "Attack Base:"), 0, wxALIGN_CENTER_VERTICAL);
    m_moveAttackBaseCtrl = new wxSpinCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 1000, 0);
    sizer->Add(m_moveAttackBaseCtrl, 1, wxEXPAND);
    
    sizer->AddGrowableCol(1, 1);
    panel->SetSizer(sizer);
    
    wxNotebook* notebook = wxDynamicCast(parent, wxNotebook);
    if (notebook) {
        notebook->AddPage(panel, "Stats");
    }
}

void MainFrame::CreateLookPage(wxWindow* parent) {
    wxPanel* panel = new wxPanel(parent);
    wxFlexGridSizer* sizer = new wxFlexGridSizer(2, 5, 5);
    
    // Look Type
    sizer->Add(new wxStaticText(panel, wxID_ANY, "Type:"), 0, wxALIGN_CENTER_VERTICAL);
    m_lookTypeCtrl = new wxSpinCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10000, 0);
    sizer->Add(m_lookTypeCtrl, 1, wxEXPAND);
    
    // Head
    sizer->Add(new wxStaticText(panel, wxID_ANY, "Head:"), 0, wxALIGN_CENTER_VERTICAL);
    m_lookHeadCtrl = new wxSpinCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 1000, 0);
    sizer->Add(m_lookHeadCtrl, 1, wxEXPAND);
    
    // Body
    sizer->Add(new wxStaticText(panel, wxID_ANY, "Body:"), 0, wxALIGN_CENTER_VERTICAL);
    m_lookBodyCtrl = new wxSpinCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 1000, 0);
    sizer->Add(m_lookBodyCtrl, 1, wxEXPAND);
    
    // Legs
    sizer->Add(new wxStaticText(panel, wxID_ANY, "Legs:"), 0, wxALIGN_CENTER_VERTICAL);
    m_lookLegsCtrl = new wxSpinCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 1000, 0);
    sizer->Add(m_lookLegsCtrl, 1, wxEXPAND);
    
    // Feet
    sizer->Add(new wxStaticText(panel, wxID_ANY, "Feet:"), 0, wxALIGN_CENTER_VERTICAL);
    m_lookFeetCtrl = new wxSpinCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 1000, 0);
    sizer->Add(m_lookFeetCtrl, 1, wxEXPAND);
    
    // Corpse
    sizer->Add(new wxStaticText(panel, wxID_ANY, "Corpse:"), 0, wxALIGN_CENTER_VERTICAL);
    m_lookCorpseCtrl = new wxSpinCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 1000, 0);
    sizer->Add(m_lookCorpseCtrl, 1, wxEXPAND);
    
    sizer->AddGrowableCol(1, 1);
    panel->SetSizer(sizer);
    
    wxNotebook* notebook = wxDynamicCast(parent, wxNotebook);
    if (notebook) {
        notebook->AddPage(panel, "Look");
    }
}

void MainFrame::CreateFlagsPage(wxWindow* parent) {
    wxPanel* panel = new wxPanel(parent);
    wxScrolledWindow* scrolled = new wxScrolledWindow(panel);
    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    wxFlexGridSizer* sizer = new wxFlexGridSizer(2, 5, 5);
    
    // Flags básicas
    sizer->Add(new wxStaticText(scrolled, wxID_ANY, "Summonable:"), 0, wxALIGN_CENTER_VERTICAL);
    m_summonableCtrl = new wxCheckBox(scrolled, wxID_ANY, "");
    sizer->Add(m_summonableCtrl, 1, wxEXPAND);
    
    sizer->Add(new wxStaticText(scrolled, wxID_ANY, "Attackable:"), 0, wxALIGN_CENTER_VERTICAL);
    m_attackableCtrl = new wxCheckBox(scrolled, wxID_ANY, "");
    sizer->Add(m_attackableCtrl, 1, wxEXPAND);
    
    sizer->Add(new wxStaticText(scrolled, wxID_ANY, "Hostile:"), 0, wxALIGN_CENTER_VERTICAL);
    m_hostileCtrl = new wxCheckBox(scrolled, wxID_ANY, "");
    sizer->Add(m_hostileCtrl, 1, wxEXPAND);
    
    sizer->Add(new wxStaticText(scrolled, wxID_ANY, "Passive:"), 0, wxALIGN_CENTER_VERTICAL);
    m_passiveCtrl = new wxCheckBox(scrolled, wxID_ANY, "");
    sizer->Add(m_passiveCtrl, 1, wxEXPAND);
    
    // ... (adicionar controles para todas as outras flags)
    
    scrolled->SetSizer(sizer);
    scrolled->SetScrollRate(10, 10);
    scrolled->FitInside();
    
    mainSizer->Add(scrolled, 1, wxEXPAND | wxALL, 5);
    panel->SetSizer(mainSizer);
    
    wxNotebook* notebook = wxDynamicCast(parent, wxNotebook);
    if (notebook) {
        notebook->AddPage(panel, "Flags");
    }
}

void MainFrame::CreateMovesPage(wxWindow* parent) {
    wxPanel* panel = new wxPanel(parent);
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    
    m_movesList = new wxListBox(panel, wxID_ANY);
    sizer->Add(m_movesList, 1, wxEXPAND | wxALL, 5);
    
    wxBoxSizer* btnSizer = new wxBoxSizer(wxHORIZONTAL);
    btnSizer->Add(new wxButton(panel, ID_ADD_MOVE, "Add"), 0, wxRIGHT, 5);
    btnSizer->Add(new wxButton(panel, ID_EDIT_MOVE, "Edit"), 0, wxRIGHT, 5);
    btnSizer->Add(new wxButton(panel, ID_REMOVE_MOVE, "Remove"), 0, wxRIGHT, 5);
    sizer->Add(btnSizer, 0, wxALIGN_RIGHT | wxALL, 5);
    
    panel->SetSizer(sizer);
    
    wxNotebook* notebook = wxDynamicCast(parent, wxNotebook);
    if (notebook) {
        notebook->AddPage(panel, "Moves");
    }
}

void MainFrame::CreateAttacksPage(wxWindow* parent) {
    wxPanel* panel = new wxPanel(parent);
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    
    m_attacksList = new wxListBox(panel, wxID_ANY);
    sizer->Add(m_attacksList, 1, wxEXPAND | wxALL, 5);
    
    wxBoxSizer* btnSizer = new wxBoxSizer(wxHORIZONTAL);
    btnSizer->Add(new wxButton(panel, ID_ADD_ATTACK, "Add"), 0, wxRIGHT, 5);
    btnSizer->Add(new wxButton(panel, ID_EDIT_ATTACK, "Edit"), 0, wxRIGHT, 5);
    btnSizer->Add(new wxButton(panel, ID_REMOVE_ATTACK, "Remove"), 0, wxRIGHT, 5);
    sizer->Add(btnSizer, 0, wxALIGN_RIGHT | wxALL, 5);
    
    panel->SetSizer(sizer);
    
    wxNotebook* notebook = wxDynamicCast(parent, wxNotebook);
    if (notebook) {
        notebook->AddPage(panel, "Attacks");
    }
}

// ... (implementar outras páginas de forma similar)

void MainFrame::ShowMoveDialog(MonsterMove* move) {
    wxDialog dialog(this, wxID_ANY, move ? "Edit Move" : "Add Move", wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER);
    
    wxFlexGridSizer* sizer = new wxFlexGridSizer(2, 5, 5);
    
    wxTextCtrl* nameCtrl = new wxTextCtrl(&dialog, wxID_ANY);
    wxSpinCtrl* intervalCtrl = new wxSpinCtrl(&dialog, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10000, 0);
    wxCheckBox* isTargetCtrl = new wxCheckBox(&dialog, wxID_ANY, "Is Target");
    wxSpinCtrl* rangeCtrl = new wxSpinCtrl(&dialog, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 100, 0);
    wxSpinCtrl* levelCtrl = new wxSpinCtrl(&dialog, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 100, 0);
    
    if (move) {
        nameCtrl->SetValue(move->name);
        intervalCtrl->SetValue(move->interval);
        isTargetCtrl->SetValue(move->isTarget);
        rangeCtrl->SetValue(move->range);
        levelCtrl->SetValue(move->level);
    }
    
    sizer->Add(new wxStaticText(&dialog, wxID_ANY, "Name:"), 0, wxALIGN_CENTER_VERTICAL);
    sizer->Add(nameCtrl, 1, wxEXPAND);
    sizer->Add(new wxStaticText(&dialog, wxID_ANY, "Interval:"), 0, wxALIGN_CENTER_VERTICAL);
    sizer->Add(intervalCtrl, 1, wxEXPAND);
    sizer->Add(new wxStaticText(&dialog, wxID_ANY, "Target:"), 0, wxALIGN_CENTER_VERTICAL);
    sizer->Add(isTargetCtrl, 1, wxEXPAND);
    sizer->Add(new wxStaticText(&dialog, wxID_ANY, "Range:"), 0, wxALIGN_CENTER_VERTICAL);
    sizer->Add(rangeCtrl, 1, wxEXPAND);
    sizer->Add(new wxStaticText(&dialog, wxID_ANY, "Level:"), 0, wxALIGN_CENTER_VERTICAL);
    sizer->Add(levelCtrl, 1, wxEXPAND);
    
    wxStdDialogButtonSizer* btnSizer = dialog.CreateStdDialogButtonSizer(wxOK | wxCANCEL);
    sizer->Add(btnSizer, 0, wxEXPAND | wxALL, 5);
    
    sizer->AddGrowableCol(1, 1);
    dialog.SetSizerAndFit(sizer);
    
    if (dialog.ShowModal() == wxID_OK) {
        if (!move) {
            MonsterMove newMove;
            newMove.name = nameCtrl->GetValue();
            newMove.interval = intervalCtrl->GetValue();
            newMove.isTarget = isTargetCtrl->GetValue();
            newMove.range = rangeCtrl->GetValue();
            newMove.level = levelCtrl->GetValue();
            m_monsterData.moves.push_back(newMove);
            m_movesList->Append(wxString::Format("%s (Range %d)", newMove.name, newMove.range));
        } else {
            move->name = nameCtrl->GetValue();
            move->interval = intervalCtrl->GetValue();
            move->isTarget = isTargetCtrl->GetValue();
            move->range = rangeCtrl->GetValue();
            move->level = levelCtrl->GetValue();
            
            int sel = m_movesList->GetSelection();
            m_movesList->SetString(sel, wxString::Format("%s (Range %d)", move->name, move->range));
        }
    }
}

void MainFrame::ShowAttackDialog(MonsterAttack* attack) {
    wxDialog dialog(this, wxID_ANY, attack ? "Edit Attack" : "Add Attack", wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER);
    
    wxFlexGridSizer* sizer = new wxFlexGridSizer(2, 5, 5);
    
    wxTextCtrl* nameCtrl = new wxTextCtrl(&dialog, wxID_ANY);
    wxSpinCtrl* intervalCtrl = new wxSpinCtrl(&dialog, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10000, 0);
    wxSpinCtrl* chanceCtrl = new wxSpinCtrl(&dialog, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 100, 0);
    wxCheckBox* isTargetCtrl = new wxCheckBox(&dialog, wxID_ANY, "Is Target");
    wxSpinCtrl* rangeCtrl = new wxSpinCtrl(&dialog, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 100, 0);
    wxSpinCtrl* minDamageCtrl = new wxSpinCtrl(&dialog, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, -1000, 1000, 0);
    wxSpinCtrl* maxDamageCtrl = new wxSpinCtrl(&dialog, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, -1000, 1000, 0);
    
    if (attack) {
        nameCtrl->SetValue(attack->name);
        intervalCtrl->SetValue(attack->interval);
        chanceCtrl->SetValue(attack->chance);
        isTargetCtrl->SetValue(attack->isTarget);
        rangeCtrl->SetValue(attack->range);
        minDamageCtrl->SetValue(attack->minDamage);
        maxDamageCtrl->SetValue(attack->maxDamage);
    }
    
    sizer->Add(new wxStaticText(&dialog, wxID_ANY, "Name:"), 0, wxALIGN_CENTER_VERTICAL);
    sizer->Add(nameCtrl, 1, wxEXPAND);
    sizer->Add(new wxStaticText(&dialog, wxID_ANY, "Interval:"), 0, wxALIGN_CENTER_VERTICAL);
    sizer->Add(intervalCtrl, 1, wxEXPAND);
    sizer->Add(new wxStaticText(&dialog, wxID_ANY, "Chance:"), 0, wxALIGN_CENTER_VERTICAL);
    sizer->Add(chanceCtrl, 1, wxEXPAND);
    sizer->Add(new wxStaticText(&dialog, wxID_ANY, "Target:"), 0, wxALIGN_CENTER_VERTICAL);
    sizer->Add(isTargetCtrl, 1, wxEXPAND);
    sizer->Add(new wxStaticText(&dialog, wxID_ANY, "Range:"), 0, wxALIGN_CENTER_VERTICAL);
    sizer->Add(rangeCtrl, 1, wxEXPAND);
    sizer->Add(new wxStaticText(&dialog, wxID_ANY, "Min Damage:"), 0, wxALIGN_CENTER_VERTICAL);
    sizer->Add(minDamageCtrl, 1, wxEXPAND);
    sizer->Add(new wxStaticText(&dialog, wxID_ANY, "Max Damage:"), 0, wxALIGN_CENTER_VERTICAL);
    sizer->Add(maxDamageCtrl, 1, wxEXPAND);
    
    wxStdDialogButtonSizer* btnSizer = dialog.CreateStdDialogButtonSizer(wxOK | wxCANCEL);
    sizer->Add(btnSizer, 0, wxEXPAND | wxALL, 5);
    
    sizer->AddGrowableCol(1, 1);
    dialog.SetSizerAndFit(sizer);
    
    if (dialog.ShowModal() == wxID_OK) {
        if (!attack) {
            MonsterAttack newAttack;
            newAttack.name = nameCtrl->GetValue();
            newAttack.interval = intervalCtrl->GetValue();
            newAttack.chance = chanceCtrl->GetValue();
            newAttack.isTarget = isTargetCtrl->GetValue();
            newAttack.range = rangeCtrl->GetValue();
            newAttack.minDamage = minDamageCtrl->GetValue();
            newAttack.maxDamage = maxDamageCtrl->GetValue();
            m_monsterData.attacks.push_back(newAttack);
            m_attacksList->Append(wxString::Format("%s (%d-%d dmg)", newAttack.name, newAttack.minDamage, newAttack.maxDamage));
        } else {
            attack->name = nameCtrl->GetValue();
            attack->interval = intervalCtrl->GetValue();
            attack->chance = chanceCtrl->GetValue();
            attack->isTarget = isTargetCtrl->GetValue();
            attack->range = rangeCtrl->GetValue();
            attack->minDamage = minDamageCtrl->GetValue();
            attack->maxDamage = maxDamageCtrl->GetValue();
            
            int sel = m_attacksList->GetSelection();
            m_attacksList->SetString(sel, wxString::Format("%s (%d-%d dmg)", attack->name, attack->minDamage, attack->maxDamage));
        }
    }
}

void MainFrame::CreateEvolutionsPage(wxWindow* parent) {
    wxPanel* panel = new wxPanel(parent);
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    
    m_evolutionsList = new wxListBox(panel, wxID_ANY);
    sizer->Add(m_evolutionsList, 1, wxEXPAND | wxALL, 5);
    
    wxBoxSizer* btnSizer = new wxBoxSizer(wxHORIZONTAL);
    btnSizer->Add(new wxButton(panel, ID_ADD_EVOLUTION, "Add"), 0, wxRIGHT, 5);
    btnSizer->Add(new wxButton(panel, ID_EDIT_EVOLUTION, "Edit"), 0, wxRIGHT, 5);
    btnSizer->Add(new wxButton(panel, ID_REMOVE_EVOLUTION, "Remove"), 0, wxRIGHT, 5);
    sizer->Add(btnSizer, 0, wxALIGN_RIGHT | wxALL, 5);
    
    panel->SetSizer(sizer);
    
    wxNotebook* notebook = wxDynamicCast(parent, wxNotebook);
    if (notebook) {
        notebook->AddPage(panel, "Evolutions");
    }
}

void MainFrame::ShowEvolutionDialog(MonsterEvolution* evolution) {
    wxDialog dialog(this, wxID_ANY, evolution ? "Edit Evolution" : "Add Evolution", 
                   wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER);
    
    wxFlexGridSizer* sizer = new wxFlexGridSizer(2, 5, 5);
    
    wxTextCtrl* nameCtrl = new wxTextCtrl(&dialog, wxID_ANY);
    wxSpinCtrl* levelCtrl = new wxSpinCtrl(&dialog, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 1, 100, 1);
    wxSpinCtrl* chanceCtrl = new wxSpinCtrl(&dialog, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 100, 0);
    wxTextCtrl* itemNameCtrl = new wxTextCtrl(&dialog, wxID_ANY);
    wxSpinCtrl* countCtrl = new wxSpinCtrl(&dialog, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 100, 0);
    
    if (evolution) {
        nameCtrl->SetValue(evolution->name);
        levelCtrl->SetValue(evolution->level);
        chanceCtrl->SetValue(evolution->chance);
        itemNameCtrl->SetValue(evolution->itemName);
        countCtrl->SetValue(evolution->count);
    }
    
    sizer->Add(new wxStaticText(&dialog, wxID_ANY, "Name:"), 0, wxALIGN_CENTER_VERTICAL);
    sizer->Add(nameCtrl, 1, wxEXPAND);
    sizer->Add(new wxStaticText(&dialog, wxID_ANY, "Level:"), 0, wxALIGN_CENTER_VERTICAL);
    sizer->Add(levelCtrl, 1, wxEXPAND);
    sizer->Add(new wxStaticText(&dialog, wxID_ANY, "Chance:"), 0, wxALIGN_CENTER_VERTICAL);
    sizer->Add(chanceCtrl, 1, wxEXPAND);
    sizer->Add(new wxStaticText(&dialog, wxID_ANY, "Item:"), 0, wxALIGN_CENTER_VERTICAL);
    sizer->Add(itemNameCtrl, 1, wxEXPAND);
    sizer->Add(new wxStaticText(&dialog, wxID_ANY, "Count:"), 0, wxALIGN_CENTER_VERTICAL);
    sizer->Add(countCtrl, 1, wxEXPAND);
    
    wxStdDialogButtonSizer* btnSizer = dialog.CreateStdDialogButtonSizer(wxOK | wxCANCEL);
    sizer->Add(btnSizer, 0, wxEXPAND | wxALL, 5);
    
    sizer->AddGrowableCol(1, 1);
    dialog.SetSizerAndFit(sizer);
    
    if (dialog.ShowModal() == wxID_OK) {
        if (!evolution) {
            MonsterEvolution newEvolution;
            newEvolution.name = nameCtrl->GetValue();
            newEvolution.level = levelCtrl->GetValue();
            newEvolution.chance = chanceCtrl->GetValue();
            newEvolution.itemName = itemNameCtrl->GetValue();
            newEvolution.count = countCtrl->GetValue();
            m_monsterData.evolutions.push_back(newEvolution);
            m_evolutionsList->Append(wxString::Format("%s (Level %d)", newEvolution.name, newEvolution.level));
        } else {
            evolution->name = nameCtrl->GetValue();
            evolution->level = levelCtrl->GetValue();
            evolution->chance = chanceCtrl->GetValue();
            evolution->itemName = itemNameCtrl->GetValue();
            evolution->count = countCtrl->GetValue();
            
            int sel = m_evolutionsList->GetSelection();
            m_evolutionsList->SetString(sel, wxString::Format("%s (Level %d)", evolution->name, evolution->level));
        }
    }
}

void MainFrame::OnAddEvolution(wxCommandEvent& event) {
    ShowEvolutionDialog();
}

void MainFrame::OnEditEvolution(wxCommandEvent& event) {
    int sel = m_evolutionsList->GetSelection();
    if (sel != wxNOT_FOUND) {
        ShowEvolutionDialog(&m_monsterData.evolutions[sel]);
    } else {
        wxMessageBox("Please select an evolution to edit", "No Selection", wxOK | wxICON_INFORMATION);
    }
}

void MainFrame::OnRemoveEvolution(wxCommandEvent& event) {
    int sel = m_evolutionsList->GetSelection();
    if (sel != wxNOT_FOUND) {
        m_monsterData.evolutions.erase(m_monsterData.evolutions.begin() + sel);
        m_evolutionsList->Delete(sel);
    } else {
        wxMessageBox("Please select an evolution to remove", "No Selection", wxOK | wxICON_INFORMATION);
    }
}

void MainFrame::CreateLootPage(wxWindow* parent) {
    wxPanel* panel = new wxPanel(parent);
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    
    m_lootList = new wxListBox(panel, wxID_ANY);
    sizer->Add(m_lootList, 1, wxEXPAND | wxALL, 5);
    
    wxBoxSizer* btnSizer = new wxBoxSizer(wxHORIZONTAL);
    btnSizer->Add(new wxButton(panel, ID_ADD_LOOT, "Add"), 0, wxRIGHT, 5);
    btnSizer->Add(new wxButton(panel, ID_EDIT_LOOT, "Edit"), 0, wxRIGHT, 5);
    btnSizer->Add(new wxButton(panel, ID_REMOVE_LOOT, "Remove"), 0, wxRIGHT, 5);
    sizer->Add(btnSizer, 0, wxALIGN_RIGHT | wxALL, 5);
    
    panel->SetSizer(sizer);
    
    wxNotebook* notebook = wxDynamicCast(parent, wxNotebook);
    if (notebook) {
        notebook->AddPage(panel, "Loot");
    }
}

void MainFrame::ShowLootDialog(MonsterLoot* loot) {
    wxDialog dialog(this, wxID_ANY, loot ? "Edit Loot" : "Add Loot", 
                   wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER);
    
    wxFlexGridSizer* sizer = new wxFlexGridSizer(2, 5, 5);
    
    wxTextCtrl* nameCtrl = new wxTextCtrl(&dialog, wxID_ANY);
    wxSpinCtrl* countmaxCtrl = new wxSpinCtrl(&dialog, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 1, 100, 1);
    wxSpinCtrl* chanceCtrl = new wxSpinCtrl(&dialog, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 100000, 0);
    
    if (loot) {
        nameCtrl->SetValue(loot->name);
        countmaxCtrl->SetValue(loot->countmax);
        chanceCtrl->SetValue(loot->chance);
    }
    
    sizer->Add(new wxStaticText(&dialog, wxID_ANY, "Item Name:"), 0, wxALIGN_CENTER_VERTICAL);
    sizer->Add(nameCtrl, 1, wxEXPAND);
    sizer->Add(new wxStaticText(&dialog, wxID_ANY, "Max Count:"), 0, wxALIGN_CENTER_VERTICAL);
    sizer->Add(countmaxCtrl, 1, wxEXPAND);
    sizer->Add(new wxStaticText(&dialog, wxID_ANY, "Chance:"), 0, wxALIGN_CENTER_VERTICAL);
    sizer->Add(chanceCtrl, 1, wxEXPAND);
    
    wxStdDialogButtonSizer* btnSizer = dialog.CreateStdDialogButtonSizer(wxOK | wxCANCEL);
    sizer->Add(btnSizer, 0, wxEXPAND | wxALL, 5);
    
    sizer->AddGrowableCol(1, 1);
    dialog.SetSizerAndFit(sizer);
    
    if (dialog.ShowModal() == wxID_OK) {
        if (!loot) {
            MonsterLoot newLoot;
            newLoot.name = nameCtrl->GetValue();
            newLoot.countmax = countmaxCtrl->GetValue();
            newLoot.chance = chanceCtrl->GetValue();
            m_monsterData.loot.push_back(newLoot);
            m_lootList->Append(wxString::Format("%s (Chance %d)", newLoot.name, newLoot.chance));
        } else {
            loot->name = nameCtrl->GetValue();
            loot->countmax = countmaxCtrl->GetValue();
            loot->chance = chanceCtrl->GetValue();
            
            int sel = m_lootList->GetSelection();
            m_lootList->SetString(sel, wxString::Format("%s (Chance %d)", loot->name, loot->chance));
        }
    }
}

void MainFrame::OnAddLoot(wxCommandEvent& event) {
    ShowLootDialog();
}

void MainFrame::OnEditLoot(wxCommandEvent& event) {
    int sel = m_lootList->GetSelection();
    if (sel != wxNOT_FOUND) {
        ShowLootDialog(&m_monsterData.loot[sel]);
    } else {
        wxMessageBox("Please select a loot item to edit", "No Selection", wxOK | wxICON_INFORMATION);
    }
}

void MainFrame::OnRemoveLoot(wxCommandEvent& event) {
    int sel = m_lootList->GetSelection();
    if (sel != wxNOT_FOUND) {
        m_monsterData.loot.erase(m_monsterData.loot.begin() + sel);
        m_lootList->Delete(sel);
    } else {
        wxMessageBox("Please select a loot item to remove", "No Selection", wxOK | wxICON_INFORMATION);
    }
}

void MainFrame::CreateVoicesPage(wxWindow* parent) {
    wxPanel* panel = new wxPanel(parent);
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    
    m_voicesList = new wxListBox(panel, wxID_ANY);
    sizer->Add(m_voicesList, 1, wxEXPAND | wxALL, 5);
    
    wxBoxSizer* btnSizer = new wxBoxSizer(wxHORIZONTAL);
    btnSizer->Add(new wxButton(panel, ID_ADD_VOICE, "Add"), 0, wxRIGHT, 5);
    btnSizer->Add(new wxButton(panel, ID_EDIT_VOICE, "Edit"), 0, wxRIGHT, 5);
    btnSizer->Add(new wxButton(panel, ID_REMOVE_VOICE, "Remove"), 0, wxRIGHT, 5);
    sizer->Add(btnSizer, 0, wxALIGN_RIGHT | wxALL, 5);
    
    panel->SetSizer(sizer);
    
    wxNotebook* notebook = wxDynamicCast(parent, wxNotebook);
    if (notebook) {
        notebook->AddPage(panel, "Voices");
    }
}

void MainFrame::ShowVoiceDialog(MonsterData::Voice* voice) {
    wxDialog dialog(this, wxID_ANY, voice ? "Edit Voice" : "Add Voice", 
                   wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER);
    
    wxFlexGridSizer* sizer = new wxFlexGridSizer(2, 5, 5);
    
    wxTextCtrl* sentenceCtrl = new wxTextCtrl(&dialog, wxID_ANY);
    wxSpinCtrl* intervalCtrl = new wxSpinCtrl(&dialog, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 60000, 5000);
    wxSpinCtrl* chanceCtrl = new wxSpinCtrl(&dialog, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 100, 10);
    
    if (voice) {
        sentenceCtrl->SetValue(voice->sentence);
        intervalCtrl->SetValue(voice->interval);
        chanceCtrl->SetValue(voice->chance);
    }
    
    sizer->Add(new wxStaticText(&dialog, wxID_ANY, "Sentence:"), 0, wxALIGN_CENTER_VERTICAL);
    sizer->Add(sentenceCtrl, 1, wxEXPAND);
    sizer->Add(new wxStaticText(&dialog, wxID_ANY, "Interval (ms):"), 0, wxALIGN_CENTER_VERTICAL);
    sizer->Add(intervalCtrl, 1, wxEXPAND);
    sizer->Add(new wxStaticText(&dialog, wxID_ANY, "Chance (%):"), 0, wxALIGN_CENTER_VERTICAL);
    sizer->Add(chanceCtrl, 1, wxEXPAND);
    
    wxStdDialogButtonSizer* btnSizer = dialog.CreateStdDialogButtonSizer(wxOK | wxCANCEL);
    sizer->Add(btnSizer, 0, wxEXPAND | wxALL, 5);
    
    sizer->AddGrowableCol(1, 1);
    dialog.SetSizerAndFit(sizer);
    
    if (dialog.ShowModal() == wxID_OK) {
        if (!voice) {
            MonsterData::Voice newVoice;
            newVoice.sentence = sentenceCtrl->GetValue();
            newVoice.interval = intervalCtrl->GetValue();
            newVoice.chance = chanceCtrl->GetValue();
            m_monsterData.voices.push_back(newVoice);
            m_voicesList->Append(newVoice.sentence);
        } else {
            voice->sentence = sentenceCtrl->GetValue();
            voice->interval = intervalCtrl->GetValue();
            voice->chance = chanceCtrl->GetValue();
            
            int sel = m_voicesList->GetSelection();
            m_voicesList->SetString(sel, voice->sentence);
        }
    }
}

void MainFrame::OnAddVoice(wxCommandEvent& event) {
    ShowVoiceDialog();
}

void MainFrame::OnEditVoice(wxCommandEvent& event) {
    int sel = m_voicesList->GetSelection();
    if (sel != wxNOT_FOUND) {
        ShowVoiceDialog(&m_monsterData.voices[sel]);
    } else {
        wxMessageBox("Please select a voice to edit", "No Selection", wxOK | wxICON_INFORMATION);
    }
}

void MainFrame::OnRemoveVoice(wxCommandEvent& event) {
    int sel = m_voicesList->GetSelection();
    if (sel != wxNOT_FOUND) {
        m_monsterData.voices.erase(m_monsterData.voices.begin() + sel);
        m_voicesList->Delete(sel);
    } else {
        wxMessageBox("Please select a voice to remove", "No Selection", wxOK | wxICON_INFORMATION);
    }
}

// Implementação dos handlers para moves
void MainFrame::OnAddMove(wxCommandEvent& event) {
    ShowMoveDialog();
}

void MainFrame::OnEditMove(wxCommandEvent& event) {
    int sel = m_movesList->GetSelection();
    if (sel != wxNOT_FOUND) {
        ShowMoveDialog(&m_monsterData.moves[sel]);
    } else {
        wxMessageBox("Please select a move to edit", "No Selection", wxOK | wxICON_INFORMATION);
    }
}

void MainFrame::OnRemoveMove(wxCommandEvent& event) {
    int sel = m_movesList->GetSelection();
    if (sel != wxNOT_FOUND) {
        m_monsterData.moves.erase(m_monsterData.moves.begin() + sel);
        m_movesList->Delete(sel);
    } else {
        wxMessageBox("Please select a move to remove", "No Selection", wxOK | wxICON_INFORMATION);
    }
}

// Implementação dos handlers para attacks
void MainFrame::OnAddAttack(wxCommandEvent& event) {
    ShowAttackDialog();
}

void MainFrame::OnEditAttack(wxCommandEvent& event) {
    int sel = m_attacksList->GetSelection();
    if (sel != wxNOT_FOUND) {
        ShowAttackDialog(&m_monsterData.attacks[sel]);
    } else {
        wxMessageBox("Please select an attack to edit", "No Selection", wxOK | wxICON_INFORMATION);
    }
}

void MainFrame::OnRemoveAttack(wxCommandEvent& event) {
    int sel = m_attacksList->GetSelection();
    if (sel != wxNOT_FOUND) {
        m_monsterData.attacks.erase(m_monsterData.attacks.begin() + sel);
        m_attacksList->Delete(sel);
    } else {
        wxMessageBox("Please select an attack to remove", "No Selection", wxOK | wxICON_INFORMATION);
    }
}

void MainFrame::CreateTargetChangePage(wxWindow* parent) {
    wxPanel* panel = new wxPanel(parent);
    wxFlexGridSizer* sizer = new wxFlexGridSizer(2, 5, 5);
    
    // Interval
    sizer->Add(new wxStaticText(panel, wxID_ANY, "Interval:"), 0, wxALIGN_CENTER_VERTICAL);
    m_targetChangeIntervalCtrl = new wxSpinCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10000, 5000);
    sizer->Add(m_targetChangeIntervalCtrl, 1, wxEXPAND);
    
    // Chance
    sizer->Add(new wxStaticText(panel, wxID_ANY, "Chance:"), 0, wxALIGN_CENTER_VERTICAL);
    m_targetChangeChanceCtrl = new wxSpinCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 100, 0);
    sizer->Add(m_targetChangeChanceCtrl, 1, wxEXPAND);
    
    sizer->AddGrowableCol(1, 1);
    panel->SetSizer(sizer);
    
    wxNotebook* notebook = wxDynamicCast(parent, wxNotebook);
    if (notebook) {
        notebook->AddPage(panel, "Target Change");
    }
}

// Implementação similar para evolutions, loot e voices

void MainFrame::OnOpen(wxCommandEvent& event) {
    wxFileDialog openFileDialog(this, "Open Monster XML", "", "", 
                              "XML files (*.xml)|*.xml", wxFD_OPEN|wxFD_FILE_MUST_EXIST);
    
    if (openFileDialog.ShowModal() == wxID_CANCEL) return;
    
    if (m_monsterData.LoadFromXML(openFileDialog.GetPath())) {
        // Atualizar controles com os dados carregados
        
        // Informações Gerais
        m_nameCtrl->SetValue(m_monsterData.name);
        m_descCtrl->SetValue(m_monsterData.nameDescription);
        m_raceCtrl->SetValue(m_monsterData.race);
        m_race2Ctrl->SetValue(m_monsterData.race2);
        m_expCtrl->SetValue(m_monsterData.experience);
        m_speedCtrl->SetValue(m_monsterData.speed);
        m_manacostCtrl->SetValue(m_monsterData.manacost);
        
        // Level e Health
        m_minLevelCtrl->SetValue(m_monsterData.minLevel);
        m_maxLevelCtrl->SetValue(m_monsterData.maxLevel);
        m_healthNowCtrl->SetValue(m_monsterData.healthNow);
        m_healthMaxCtrl->SetValue(m_monsterData.healthMax);
        
        // Look
        m_lookTypeCtrl->SetValue(m_monsterData.lookType);
        m_lookHeadCtrl->SetValue(m_monsterData.lookHead);
        m_lookBodyCtrl->SetValue(m_monsterData.lookBody);
        m_lookLegsCtrl->SetValue(m_monsterData.lookLegs);
        m_lookFeetCtrl->SetValue(m_monsterData.lookFeet);
        m_lookCorpseCtrl->SetValue(m_monsterData.lookCorpse);
        
        // Target Change
        m_targetChangeIntervalCtrl->SetValue(m_monsterData.targetChangeInterval);
        m_targetChangeChanceCtrl->SetValue(m_monsterData.targetChangeChance);
        
        // Flags
        m_summonableCtrl->SetValue(m_monsterData.flags.summonable);
        m_attackableCtrl->SetValue(m_monsterData.flags.attackable);
        m_hostileCtrl->SetValue(m_monsterData.flags.hostile);
        m_passiveCtrl->SetValue(m_monsterData.flags.passive);
        m_illusionableCtrl->SetValue(m_monsterData.flags.illusionable);
        m_convinceableCtrl->SetValue(m_monsterData.flags.convinceable);
        m_pushableCtrl->SetValue(m_monsterData.flags.pushable);
        m_canpushitemsCtrl->SetValue(m_monsterData.flags.canpushitems);
        m_canpushcreaturesCtrl->SetValue(m_monsterData.flags.canpushcreatures);
        m_targetdistanceCtrl->SetValue(m_monsterData.flags.targetdistance);
        m_staticattackCtrl->SetValue(m_monsterData.flags.staticattack);
        m_runonhealthCtrl->SetValue(m_monsterData.flags.runonhealth);
        m_dexentryCtrl->SetValue(m_monsterData.flags.dexentry);
        m_portraitidCtrl->SetValue(m_monsterData.flags.portraitid);
        m_hasshinyCtrl->SetValue(m_monsterData.flags.hasshiny);
        m_hasmegaCtrl->SetValue(m_monsterData.flags.hasmega);
        m_flyableCtrl->SetValue(m_monsterData.flags.flyable);
        m_rideableCtrl->SetValue(m_monsterData.flags.rideable);
        m_surfableCtrl->SetValue(m_monsterData.flags.surfable);
        m_canteleportCtrl->SetValue(m_monsterData.flags.canteleport);
        m_catchchanceCtrl->SetValue(m_monsterData.flags.catchchance);
        m_moveMagicAttackBaseCtrl->SetValue(m_monsterData.flags.moveMagicAttackBase);
        m_moveMagicDefenseBaseCtrl->SetValue(m_monsterData.flags.moveMagicDefenseBase);
        m_moveAttackBaseCtrl->SetValue(m_monsterData.flags.moveAttackBase);
        
        // Stats
        m_armorCtrl->SetValue(m_monsterData.armor);
        m_defenseCtrl->SetValue(m_monsterData.defense);
        
        // Carregar listas
        m_movesList->Clear();
        for (const auto& move : m_monsterData.moves) {
            m_movesList->Append(wxString::Format("%s (Range %d)", move.name, move.range));
        }
        
        m_attacksList->Clear();
        for (const auto& attack : m_monsterData.attacks) {
            m_attacksList->Append(wxString::Format("%s (%d-%d dmg)", attack.name, attack.minDamage, attack.maxDamage));
        }
        
        m_evolutionsList->Clear();
        for (const auto& evolution : m_monsterData.evolutions) {
            m_evolutionsList->Append(wxString::Format("%s (Level %d)", evolution.name, evolution.level));
        }
        
        m_lootList->Clear();
        for (const auto& item : m_monsterData.loot) {
            m_lootList->Append(wxString::Format("%s (Chance %d)", item.name, item.chance));
        }
        
        m_voicesList->Clear();
        for (const auto& voice : m_monsterData.voices) {
            m_voicesList->Append(voice.sentence);
        }
    } else {
        wxMessageBox("Failed to load XML file", "Error", wxOK | wxICON_ERROR);
    }
}

void MainFrame::OnSave(wxCommandEvent& event) {
    // Atualizar dados na memória a partir dos controles
    
    // Informações Gerais
    m_monsterData.name = m_nameCtrl->GetValue();
    m_monsterData.nameDescription = m_descCtrl->GetValue();
    m_monsterData.race = m_raceCtrl->GetValue();
    m_monsterData.race2 = m_race2Ctrl->GetValue();
    m_monsterData.experience = m_expCtrl->GetValue();
    m_monsterData.speed = m_speedCtrl->GetValue();
    m_monsterData.manacost = m_manacostCtrl->GetValue();
    
    // Level e Health
    m_monsterData.minLevel = m_minLevelCtrl->GetValue();
    m_monsterData.maxLevel = m_maxLevelCtrl->GetValue();
    m_monsterData.healthNow = m_healthNowCtrl->GetValue();
    m_monsterData.healthMax = m_healthMaxCtrl->GetValue();
    
    // Look
    m_monsterData.lookType = m_lookTypeCtrl->GetValue();
    m_monsterData.lookHead = m_lookHeadCtrl->GetValue();
    m_monsterData.lookBody = m_lookBodyCtrl->GetValue();
    m_monsterData.lookLegs = m_lookLegsCtrl->GetValue();
    m_monsterData.lookFeet = m_lookFeetCtrl->GetValue();
    m_monsterData.lookCorpse = m_lookCorpseCtrl->GetValue();
    
    // Target Change
    m_monsterData.targetChangeInterval = m_targetChangeIntervalCtrl->GetValue();
    m_monsterData.targetChangeChance = m_targetChangeChanceCtrl->GetValue();
    
    // Flags
    m_monsterData.flags.summonable = m_summonableCtrl->GetValue();
    m_monsterData.flags.attackable = m_attackableCtrl->GetValue();
    m_monsterData.flags.hostile = m_hostileCtrl->GetValue();
    m_monsterData.flags.passive = m_passiveCtrl->GetValue();
    m_monsterData.flags.illusionable = m_illusionableCtrl->GetValue();
    m_monsterData.flags.convinceable = m_convinceableCtrl->GetValue();
    m_monsterData.flags.pushable = m_pushableCtrl->GetValue();
    m_monsterData.flags.canpushitems = m_canpushitemsCtrl->GetValue();
    m_monsterData.flags.canpushcreatures = m_canpushcreaturesCtrl->GetValue();
    m_monsterData.flags.targetdistance = m_targetdistanceCtrl->GetValue();
    m_monsterData.flags.staticattack = m_staticattackCtrl->GetValue();
    m_monsterData.flags.runonhealth = m_runonhealthCtrl->GetValue();
    m_monsterData.flags.dexentry = m_dexentryCtrl->GetValue();
    m_monsterData.flags.portraitid = m_portraitidCtrl->GetValue();
    m_monsterData.flags.hasshiny = m_hasshinyCtrl->GetValue();
    m_monsterData.flags.hasmega = m_hasmegaCtrl->GetValue();
    m_monsterData.flags.flyable = m_flyableCtrl->GetValue();
    m_monsterData.flags.rideable = m_rideableCtrl->GetValue();
    m_monsterData.flags.surfable = m_surfableCtrl->GetValue();
    m_monsterData.flags.canteleport = m_canteleportCtrl->GetValue();
    m_monsterData.flags.catchchance = m_catchchanceCtrl->GetValue();
    m_monsterData.flags.moveMagicAttackBase = m_moveMagicAttackBaseCtrl->GetValue();
    m_monsterData.flags.moveMagicDefenseBase = m_moveMagicDefenseBaseCtrl->GetValue();
    m_monsterData.flags.moveAttackBase = m_moveAttackBaseCtrl->GetValue();
    
    // Stats
    m_monsterData.armor = m_armorCtrl->GetValue();
    m_monsterData.defense = m_defenseCtrl->GetValue();
    
    wxFileDialog saveFileDialog(this, "Save Monster XML", "", "", 
                              "XML files (*.xml)|*.xml", wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
    
    if (saveFileDialog.ShowModal() == wxID_CANCEL) return;
    
    if (!m_monsterData.SaveToXML(saveFileDialog.GetPath())) {
        wxMessageBox("Failed to save XML file", "Error", wxOK | wxICON_ERROR);
    }
}

void MainFrame::OnExit(wxCommandEvent& event) {
    Close(true);
}