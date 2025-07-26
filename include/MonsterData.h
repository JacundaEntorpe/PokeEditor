// Projeto completo para o editor de monstros em C++ com wxWidgets 3.2.8
// Estrutura inicial de MonsterData.h com melhorias

#ifndef MONSTER_DATA_H
#define MONSTER_DATA_H

#include <wx/string.h>
#include <wx/xml/xml.h>
#include <vector>

struct MonsterMove {
    wxString name;
    int interval;
    bool isTarget;
    int range;
    int level;
};

struct MonsterEvolution {
    wxString name;
    int level;
    int chance;
    wxString itemName;
    int count;
};

struct MonsterLoot {
    wxString name;
    int countmax;
    int chance;
};

class MonsterData {
public:
    bool LoadFromXML(const wxString& filename);
    bool SaveToXML(const wxString& filename);

    // Informacoes Gerais
    wxString name;
    wxString nameDescription;
    wxString race;
    wxString race2;
    int experience;
    int dexID;

    // Stats
    int speed = 0;
    int moveMagicAttackBase = 0;
    int moveMagicDefenseBase = 0;
    int moveAttackBase = 0;
    int melee = 0;
    int defense = 0;

    std::vector<MonsterMove> moves;
    std::vector<MonsterEvolution> evolutions;
    std::vector<MonsterLoot> loot;

private:
    wxXmlNode* FindChild(wxXmlNode* parent, const wxString& name);
    int GetFlagValue(wxXmlNode* flagsNode, const wxString& name);
};

#endif // MONSTER_DATA_H