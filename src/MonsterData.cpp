#include "MonsterData.h"
#include <wx/xml/xml.h>

bool MonsterData::LoadFromXML(const wxString& filename) {
    wxXmlDocument doc;
    if (!doc.Load(filename)) {
        return false;
    }

    wxXmlNode* root = doc.GetRoot();
    if (!root || root->GetName() != "monster") {
        return false;
    }

    // Atributos básicos
    name = root->GetAttribute("name", "");
    nameDescription = root->GetAttribute("nameDescription", "");
    race = root->GetAttribute("race", "");
    race2 = root->GetAttribute("race2", "");
    experience = GetAttributeInt(root, "experience");
    speed = GetAttributeInt(root, "speed");
    manacost = GetAttributeInt(root, "manacost");

    // Level
    wxXmlNode* levelNode = FindChild(root, "level");
    if (levelNode) {
        minLevel = GetAttributeInt(levelNode, "min", 1);
        maxLevel = GetAttributeInt(levelNode, "max", 10);
    }

    // Health
    wxXmlNode* healthNode = FindChild(root, "health");
    if (healthNode) {
        healthNow = GetAttributeInt(healthNode, "now");
        healthMax = GetAttributeInt(healthNode, "max");
    }

    // Look
    wxXmlNode* lookNode = FindChild(root, "look");
    if (lookNode) {
        lookType = GetAttributeInt(lookNode, "type");
        lookHead = GetAttributeInt(lookNode, "head");
        lookBody = GetAttributeInt(lookNode, "body");
        lookLegs = GetAttributeInt(lookNode, "legs");
        lookFeet = GetAttributeInt(lookNode, "feet");
        lookCorpse = GetAttributeInt(lookNode, "corpse");
    }

    // Target Change
    wxXmlNode* targetChangeNode = FindChild(root, "targetchange");
    if (targetChangeNode) {
        targetChangeInterval = GetAttributeInt(targetChangeNode, "interval", 5000);
        targetChangeChance = GetAttributeInt(targetChangeNode, "chance");
    }

    // Flags
    wxXmlNode* flagsNode = FindChild(root, "flags");
    if (flagsNode) {
        wxXmlNode* flagNode = flagsNode->GetChildren();
        while (flagNode) {
            if (flagNode->GetName() == "flag") {
                flags.summonable = GetAttributeInt(flagNode, "summonable");
                flags.attackable = GetAttributeInt(flagNode, "attackable");
                flags.hostile = GetAttributeInt(flagNode, "hostile");
                flags.passive = GetAttributeInt(flagNode, "passive");
                flags.illusionable = GetAttributeInt(flagNode, "illusionable");
                flags.convinceable = GetAttributeInt(flagNode, "convinceable");
                flags.pushable = GetAttributeInt(flagNode, "pushable");
                flags.canpushitems = GetAttributeInt(flagNode, "canpushitems");
                flags.canpushcreatures = GetAttributeInt(flagNode, "canpushcreatures");
                flags.targetdistance = GetAttributeInt(flagNode, "targetdistance", 1);
                flags.staticattack = GetAttributeInt(flagNode, "staticattack");
                flags.runonhealth = GetAttributeInt(flagNode, "runonhealth");
                flags.dexentry = GetAttributeInt(flagNode, "dexentry");
                flags.portraitid = GetAttributeInt(flagNode, "portraitid");
                flags.hasshiny = GetAttributeInt(flagNode, "hasshiny");
                flags.hasmega = GetAttributeInt(flagNode, "hasmega");
                flags.flyable = GetAttributeInt(flagNode, "flyable");
                flags.rideable = GetAttributeInt(flagNode, "rideable");
                flags.surfable = GetAttributeInt(flagNode, "surfable");
                flags.canteleport = GetAttributeInt(flagNode, "canteleport");
                flags.catchchance = GetAttributeInt(flagNode, "catchchance");
                flags.moveMagicAttackBase = GetAttributeInt(flagNode, "moveMagicAttackBase");
                flags.moveMagicDefenseBase = GetAttributeInt(flagNode, "moveMagicDefenseBase");
                flags.moveAttackBase = GetAttributeInt(flagNode, "moveAttackBase");
            }
            flagNode = flagNode->GetNext();
        }
    }

    // Defesas
    wxXmlNode* defensesNode = FindChild(root, "defenses");
    if (defensesNode) {
        armor = GetAttributeInt(defensesNode, "armor");
        defense = GetAttributeInt(defensesNode, "defense");
    }

    // Voices
    voices.clear();
    wxXmlNode* voicesNode = FindChild(root, "voices");
    if (voicesNode) {
        int voicesInterval = GetAttributeInt(voicesNode, "interval", 5000);
        int voicesChance = GetAttributeInt(voicesNode, "chance", 10);
        
        wxXmlNode* voiceNode = voicesNode->GetChildren();
        while (voiceNode) {
            if (voiceNode->GetName() == "voice") {
                Voice voice;
                voice.sentence = voiceNode->GetAttribute("sentence", "");
                voice.interval = voicesInterval;
                voice.chance = voicesChance;
                voices.push_back(voice);
            }
            voiceNode = voiceNode->GetNext();
        }
    }

    // Limpar e carregar listas
    moves.clear();
    attacks.clear();
    evolutions.clear();
    loot.clear();

    // Moves
    wxXmlNode* movesNode = FindChild(root, "moves");
    if (movesNode) {
        wxXmlNode* moveNode = movesNode->GetChildren();
        while (moveNode) {
            if (moveNode->GetName() == "move") {
                MonsterMove move;
                move.name = moveNode->GetAttribute("name", "");
                move.interval = GetAttributeInt(moveNode, "interval");
                move.isTarget = GetAttributeInt(moveNode, "isTarget");
                move.range = GetAttributeInt(moveNode, "range");
                move.level = GetAttributeInt(moveNode, "level");
                moves.push_back(move);
            }
            moveNode = moveNode->GetNext();
        }
    }

    // Attacks
    wxXmlNode* attacksNode = FindChild(root, "attacks");
    if (attacksNode) {
        wxXmlNode* attackNode = attacksNode->GetChildren();
        while (attackNode) {
            if (attackNode->GetName() == "attack") {
                MonsterAttack attack;
                attack.name = attackNode->GetAttribute("name", "");
                attack.interval = GetAttributeInt(attackNode, "interval");
                attack.chance = GetAttributeInt(attackNode, "chance");
                attack.isTarget = GetAttributeInt(attackNode, "target");
                attack.range = GetAttributeInt(attackNode, "range");
                attack.minDamage = GetAttributeInt(attackNode, "min");
                attack.maxDamage = GetAttributeInt(attackNode, "max");
                attacks.push_back(attack);
            }
            attackNode = attackNode->GetNext();
        }
    }

    // Evolutions
    wxXmlNode* evolutionsNode = FindChild(root, "evolutions");
    if (evolutionsNode) {
        wxXmlNode* evolutionNode = evolutionsNode->GetChildren();
        while (evolutionNode) {
            if (evolutionNode->GetName() == "evolution") {
                MonsterEvolution evolution;
                evolution.name = evolutionNode->GetAttribute("name", "");
                evolution.level = GetAttributeInt(evolutionNode, "level");
                evolution.chance = GetAttributeInt(evolutionNode, "chance");
                evolution.itemName = evolutionNode->GetAttribute("itemName", "");
                evolution.count = GetAttributeInt(evolutionNode, "count");
                evolutions.push_back(evolution);
            }
            evolutionNode = evolutionNode->GetNext();
        }
    }

    // Loot
    wxXmlNode* lootNode = FindChild(root, "loot");
    if (lootNode) {
        wxXmlNode* itemNode = lootNode->GetChildren();
        while (itemNode) {
            if (itemNode->GetName() == "item") {
                MonsterLoot item;
                item.name = itemNode->GetAttribute("name", "");
                item.countmax = GetAttributeInt(itemNode, "countmax");
                item.chance = GetAttributeInt(itemNode, "chance");
                loot.push_back(item);
            }
            itemNode = itemNode->GetNext();
        }
    }

    return true;
}

bool MonsterData::SaveToXML(const wxString& filename) {
    wxXmlDocument doc;
    wxXmlNode* root = new wxXmlNode(NULL, wxXML_ELEMENT_NODE, "monster");
    
    // Atributos básicos
    root->AddAttribute("name", name);
    root->AddAttribute("nameDescription", nameDescription);
    root->AddAttribute("race", race);
    root->AddAttribute("race2", race2);
    root->AddAttribute("experience", wxString::Format("%d", experience));
    root->AddAttribute("speed", wxString::Format("%d", speed));
    if (manacost > 0) {
        root->AddAttribute("manacost", wxString::Format("%d", manacost));
    }
    
    // Level
    wxXmlNode* levelNode = new wxXmlNode(root, wxXML_ELEMENT_NODE, "level");
    levelNode->AddAttribute("min", wxString::Format("%d", minLevel));
    levelNode->AddAttribute("max", wxString::Format("%d", maxLevel));
    
    // Health
    wxXmlNode* healthNode = new wxXmlNode(root, wxXML_ELEMENT_NODE, "health");
    healthNode->AddAttribute("now", wxString::Format("%d", healthNow));
    healthNode->AddAttribute("max", wxString::Format("%d", healthMax));
    
    // Look
    wxXmlNode* lookNode = new wxXmlNode(root, wxXML_ELEMENT_NODE, "look");
    lookNode->AddAttribute("type", wxString::Format("%d", lookType));
    lookNode->AddAttribute("head", wxString::Format("%d", lookHead));
    lookNode->AddAttribute("body", wxString::Format("%d", lookBody));
    lookNode->AddAttribute("legs", wxString::Format("%d", lookLegs));
    lookNode->AddAttribute("feet", wxString::Format("%d", lookFeet));
    lookNode->AddAttribute("corpse", wxString::Format("%d", lookCorpse));
    
    // Target Change
    wxXmlNode* targetChangeNode = new wxXmlNode(root, wxXML_ELEMENT_NODE, "targetchange");
    targetChangeNode->AddAttribute("interval", wxString::Format("%d", targetChangeInterval));
    targetChangeNode->AddAttribute("chance", wxString::Format("%d", targetChangeChance));
    
    // Flags (todas as flags são escritas, mesmo com valor 0)
    wxXmlNode* flagsNode = new wxXmlNode(root, wxXML_ELEMENT_NODE, "flags");
    AddFlag(flagsNode, "summonable", flags.summonable);
    AddFlag(flagsNode, "attackable", flags.attackable);
    AddFlag(flagsNode, "hostile", flags.hostile);
    AddFlag(flagsNode, "passive", flags.passive);
    AddFlag(flagsNode, "illusionable", flags.illusionable);
    AddFlag(flagsNode, "convinceable", flags.convinceable);
    AddFlag(flagsNode, "pushable", flags.pushable);
    AddFlag(flagsNode, "canpushitems", flags.canpushitems);
    AddFlag(flagsNode, "canpushcreatures", flags.canpushcreatures);
    AddFlag(flagsNode, "targetdistance", flags.targetdistance);
    AddFlag(flagsNode, "staticattack", flags.staticattack);
    AddFlag(flagsNode, "runonhealth", flags.runonhealth);
    AddFlag(flagsNode, "dexentry", flags.dexentry);
    AddFlag(flagsNode, "portraitid", flags.portraitid);
    AddFlag(flagsNode, "hasshiny", flags.hasshiny);
    AddFlag(flagsNode, "hasmega", flags.hasmega);
    AddFlag(flagsNode, "flyable", flags.flyable);
    AddFlag(flagsNode, "rideable", flags.rideable);
    AddFlag(flagsNode, "surfable", flags.surfable);
    AddFlag(flagsNode, "canteleport", flags.canteleport);
    AddFlag(flagsNode, "catchchance", flags.catchchance);
    AddFlag(flagsNode, "moveMagicAttackBase", flags.moveMagicAttackBase);
    AddFlag(flagsNode, "moveMagicDefenseBase", flags.moveMagicDefenseBase);
    AddFlag(flagsNode, "moveAttackBase", flags.moveAttackBase);
    
    // Defesas
    wxXmlNode* defensesNode = new wxXmlNode(root, wxXML_ELEMENT_NODE, "defenses");
    defensesNode->AddAttribute("armor", wxString::Format("%d", armor));
    defensesNode->AddAttribute("defense", wxString::Format("%d", defense));
    
    // Voices
    if (!voices.empty()) {
        wxXmlNode* voicesNode = new wxXmlNode(root, wxXML_ELEMENT_NODE, "voices");
        voicesNode->AddAttribute("interval", wxString::Format("%d", voices[0].interval));
        voicesNode->AddAttribute("chance", wxString::Format("%d", voices[0].chance));
        
        for (const auto& voice : voices) {
            wxXmlNode* voiceNode = new wxXmlNode(voicesNode, wxXML_ELEMENT_NODE, "voice");
            voiceNode->AddAttribute("sentence", voice.sentence);
        }
    }
    
    // Moves
    if (!moves.empty()) {
        wxXmlNode* movesNode = new wxXmlNode(root, wxXML_ELEMENT_NODE, "moves");
        for (const auto& move : moves) {
            wxXmlNode* moveNode = new wxXmlNode(movesNode, wxXML_ELEMENT_NODE, "move");
            moveNode->AddAttribute("name", move.name);
            moveNode->AddAttribute("interval", wxString::Format("%d", move.interval));
            moveNode->AddAttribute("isTarget", wxString::Format("%d", move.isTarget));
            moveNode->AddAttribute("range", wxString::Format("%d", move.range));
            moveNode->AddAttribute("level", wxString::Format("%d", move.level));
        }
    }
    
    // Attacks
    if (!attacks.empty()) {
        wxXmlNode* attacksNode = new wxXmlNode(root, wxXML_ELEMENT_NODE, "attacks");
        for (const auto& attack : attacks) {
            wxXmlNode* attackNode = new wxXmlNode(attacksNode, wxXML_ELEMENT_NODE, "attack");
            attackNode->AddAttribute("name", attack.name);
            attackNode->AddAttribute("interval", wxString::Format("%d", attack.interval));
            if (attack.chance > 0) {
                attackNode->AddAttribute("chance", wxString::Format("%d", attack.chance));
            }
            attackNode->AddAttribute("target", wxString::Format("%d", attack.isTarget));
            attackNode->AddAttribute("range", wxString::Format("%d", attack.range));
            attackNode->AddAttribute("min", wxString::Format("%d", attack.minDamage));
            attackNode->AddAttribute("max", wxString::Format("%d", attack.maxDamage));
        }
    }
    
    // Evolutions
    if (!evolutions.empty()) {
        wxXmlNode* evolutionsNode = new wxXmlNode(root, wxXML_ELEMENT_NODE, "evolutions");
        for (const auto& evolution : evolutions) {
            wxXmlNode* evolutionNode = new wxXmlNode(evolutionsNode, wxXML_ELEMENT_NODE, "evolution");
            evolutionNode->AddAttribute("name", evolution.name);
            evolutionNode->AddAttribute("level", wxString::Format("%d", evolution.level));
            evolutionNode->AddAttribute("chance", wxString::Format("%d", evolution.chance));
            evolutionNode->AddAttribute("itemName", evolution.itemName);
            evolutionNode->AddAttribute("count", wxString::Format("%d", evolution.count));
        }
    }
    
    // Loot
    if (!loot.empty()) {
        wxXmlNode* lootNode = new wxXmlNode(root, wxXML_ELEMENT_NODE, "loot");
        for (const auto& item : loot) {
            wxXmlNode* itemNode = new wxXmlNode(lootNode, wxXML_ELEMENT_NODE, "item");
            itemNode->AddAttribute("name", item.name);
            itemNode->AddAttribute("countmax", wxString::Format("%d", item.countmax));
            itemNode->AddAttribute("chance", wxString::Format("%d", item.chance));
        }
    }
    
    doc.SetRoot(root);
    return doc.Save(filename);
}

wxXmlNode* MonsterData::FindChild(wxXmlNode* parent, const wxString& name) {
    if (!parent) return nullptr;
    
    wxXmlNode* child = parent->GetChildren();
    while (child) {
        if (child->GetName() == name) {
            return child;
        }
        child = child->GetNext();
    }
    return nullptr;
}

int MonsterData::GetAttributeInt(wxXmlNode* node, const wxString& attr, int defaultValue) {
    long value = defaultValue;
    node->GetAttribute(attr, wxString::Format("%d", defaultValue)).ToLong(&value);
    return value;
}

void MonsterData::AddFlag(wxXmlNode* parent, const wxString& name, int value) {
    wxXmlNode* flagNode = new wxXmlNode(parent, wxXML_ELEMENT_NODE, "flag");
    flagNode->AddAttribute(name, wxString::Format("%d", value));
}