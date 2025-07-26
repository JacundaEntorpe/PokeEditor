#include "MonsterData.h"
#include <wx/xml/xml.h>
#include <wx/string.h>

bool MonsterData::LoadFromXML(const wxString& filename) {
    wxXmlDocument doc;
    if (!doc.Load(filename)) {
        return false;
    }

    wxXmlNode* root = doc.GetRoot();
    if (!root || root->GetName() != "monster") {
        return false;
    }

    // Ler atributos b?sicos
    name = root->GetAttribute("name", "");
    nameDescription = root->GetAttribute("nameDescription", "");
    race = root->GetAttribute("race", "");
    race2 = root->GetAttribute("race2", "");
    root->GetAttribute("experience", "0").ToInt(&experience);
    root->GetAttribute("speed", "0").ToInt(&speed);

    // Ler flags - m?todo corrigido para encontrar o n? "flags"
    wxXmlNode* flagsNode = root->GetChildren();
    while (flagsNode) {
        if (flagsNode->GetName() == "flags") {
            // Processar flags
            wxXmlNode* flagNode = flagsNode->GetChildren();
            while (flagNode) {
                if (flagNode->GetName() == "flag") {
                    wxString value = flagNode->GetAttribute("moveMagicAttackBase", "0");
                    value.ToInt(&moveMagicAttackBase);
                    // Processar outros flags...
                }
                flagNode = flagNode->GetNext();
            }
            break;
        }
        flagsNode = flagsNode->GetNext();
    }

    // Limpar listas antes de carregar
    moves.clear();
    evolutions.clear();
    loot.clear();

    // Processar moves
    wxXmlNode* movesNode = root->GetChildren();
    while (movesNode) {
        if (movesNode->GetName() == "moves") {
            wxXmlNode* moveNode = movesNode->GetChildren();
            while (moveNode) {
                if (moveNode->GetName() == "move") {
                    MonsterMove move;
                    move.name = moveNode->GetAttribute("name", "");
                    moveNode->GetAttribute("interval", "0").ToInt(&move.interval);
                    moveNode->GetAttribute("isTarget", "0").ToInt((int*)&move.isTarget);
                    moveNode->GetAttribute("range", "0").ToInt(&move.range);
                    moveNode->GetAttribute("level", "0").ToInt(&move.level);
                    moves.push_back(move);
                }
                moveNode = moveNode->GetNext();
            }
            break;
        }
        movesNode = movesNode->GetNext();
    }

    // Processar evolutions (similar ao moves)
    // Processar loot (similar ao moves)

    return true;
}

bool MonsterData::SaveToXML(const wxString& filename) {
    wxXmlDocument doc;
    wxXmlNode* root = new wxXmlNode(NULL, wxXML_ELEMENT_NODE, "monster");
    
    // Adicionar atributos b?sicos
    root->AddAttribute("name", name);
    root->AddAttribute("nameDescription", nameDescription);
    root->AddAttribute("race", race);
    root->AddAttribute("race2", race2);
    root->AddAttribute("experience", wxString::Format("%d", experience));
    root->AddAttribute("speed", wxString::Format("%d", speed));
    
    // Adicionar n?s para flags, moves, evolutions, loot...
    
    doc.SetRoot(root);
    return doc.Save(filename);
}