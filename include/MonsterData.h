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

struct MonsterAttack {
    wxString name;
    int interval;
    int chance;
    bool isTarget;
    int range;
    int minDamage;
    int maxDamage;
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

    // Informações Gerais
    wxString name;
    wxString nameDescription;
    wxString race;
    wxString race2;
    int experience = 0;
    int dexID = 0;
    int speed = 0;
    int manacost = 0;

    // Level e Saúde
    int minLevel = 1;
    int maxLevel = 10;
    int healthNow = 0;
    int healthMax = 0;

    // Look
    int lookType = 0;
    int lookHead = 0;
    int lookBody = 0;
    int lookLegs = 0;
    int lookFeet = 0;
    int lookCorpse = 0;

    // Target Change
    int targetChangeInterval = 5000;
    int targetChangeChance = 0;

    // Flags
    struct {
        int summonable = 0;
        int attackable = 0;
        int hostile = 0;
        int passive = 0;
        int illusionable = 0;
        int convinceable = 0;
        int pushable = 0;
        int canpushitems = 0;
        int canpushcreatures = 0;
        int targetdistance = 1;
        int staticattack = 0;
        int runonhealth = 0;
        int dexentry = 0;
        int portraitid = 0;
        int hasshiny = 0;
        int hasmega = 0;
        int flyable = 0;
        int rideable = 0;
        int surfable = 0;
        int canteleport = 0;
        int catchchance = 0;
        int moveMagicAttackBase = 0;
        int moveMagicDefenseBase = 0;
        int moveAttackBase = 0;
    } flags;

    // Defesas
    int armor = 0;
    int defense = 0;

    // Voices
    struct Voice {
        wxString sentence;
        int interval = 5000;
        int chance = 10;
    };
    std::vector<Voice> voices;

    // Listas
    std::vector<MonsterMove> moves;
    std::vector<MonsterAttack> attacks;
    std::vector<MonsterEvolution> evolutions;
    std::vector<MonsterLoot> loot;

private:
    wxXmlNode* FindChild(wxXmlNode* parent, const wxString& name);
    int GetAttributeInt(wxXmlNode* node, const wxString& attr, int defaultValue = 0);
    void AddFlag(wxXmlNode* parent, const wxString& name, int value);
};

#endif // MONSTER_DATA_H