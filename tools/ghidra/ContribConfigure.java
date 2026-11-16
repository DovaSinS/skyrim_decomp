// Original contributor tooling. Disable external symbol acquisition before local analysis.
// @category SkyrimResearch
import ghidra.app.script.GhidraScript;
import ghidra.framework.options.Options;
import ghidra.program.model.listing.Program;
public class ContribConfigure extends GhidraScript {
    @Override public void run() throws Exception {
        Options options = currentProgram.getOptions(Program.ANALYSIS_PROPERTIES);
        for (String name : new String[] { "PDB Universal", "PDB MSDIA" }) {
            if (options.contains(name)) options.setBoolean(name, false);
        }
    }
}
