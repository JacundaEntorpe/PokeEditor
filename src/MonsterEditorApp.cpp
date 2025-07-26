#include "MonsterEditorApp.h"
#include "MainFrame.h"

bool MonsterEditorApp::OnInit() {
    MainFrame *frame = new MainFrame("Monster Editor");
    frame->Show(true);
    return true;
}