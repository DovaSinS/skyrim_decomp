// Private checkpoint only; the Python worker verifies the headless exit and saved project too.
// @category SkyrimResearch
import java.nio.file.*;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Program;
public class ContribCheckpoint extends GhidraScript {
    @Override public void run() throws Exception {
        for (String name : new String[] { "PDB Universal", "PDB MSDIA" }) {
            if (currentProgram.getOptions(Program.ANALYSIS_PROPERTIES).getBoolean(name, false)) {
                throw new IllegalStateException("External PDB analysis was not disabled");
            }
        }
        Files.writeString(Paths.get(getScriptArgs()[0]), "complete\n");
    }
}
