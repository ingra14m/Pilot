#include <iostream>
#include <string>
#include <thread>
#include <unordered_map>

#include "editor/include/editor.h"
#include "runtime/engine.h"

// https://gcc.gnu.org/onlinedocs/cpp/Stringizing.html
#define PILOT_XSTR(s) PILOT_STR(s)   // 这是从Cmake里面传进来的变量
#define PILOT_STR(s) #s

int main(int argc, char **argv) {
    // pilot root folder = "/Users/ingram14/Git_Project/GAMES104/Pilot/bin/"
    std::filesystem::path pilot_root_folder = std::filesystem::path(PILOT_XSTR(PILOT_ROOT_DIR));

    Pilot::EngineInitParams params;
    params.m_root_folder = pilot_root_folder;
    params.m_config_file_path = pilot_root_folder / "PilotEditor.ini";

    /*
     * PilotEditor最终的文件路径：
     * /Users/ingram14/Git_Project/GAMES104/Pilot/bin/asset
     * /Users/ingram14/Git_Project/GAMES104/Pilot/bin/schema  这个目前好像还没有加进来
     * /Users/ingram14/Git_Project/GAMES104/Pilot/bin/asset/world/hello.world.json
     * /Users/ingram14/Git_Project/GAMES104/Pilot/bin/resource/PilotEditorBigIcon.png
     * /Users/ingram14/Git_Project/GAMES104/Pilot/bin/resource/PilotEditorSmallIcon.png
     * /Users/ingram14/Git_Project/GAMES104/Pilot/bin/resource/PilotEditorFont.TTF
     *
     */
    Pilot::PilotEngine::getInstance().startEngine(params);
    Pilot::PilotEngine::getInstance().initialize();

    Pilot::PilotEditor::getInstance().initialize(&(Pilot::PilotEngine::getInstance()));

    Pilot::PilotEditor::getInstance().run();

    Pilot::PilotEditor::getInstance().clear();

    Pilot::PilotEngine::getInstance().clear();
    Pilot::PilotEngine::getInstance().shutdownEngine();

    return 0;
}
