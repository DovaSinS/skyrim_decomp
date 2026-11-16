// Public naming hints only. RTTI names are recovered locally by Ghidra's built-in analyzers.
// @category SkyrimResearch
import java.nio.file.*;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.SourceType;
public class ContribNames extends GhidraScript {
    @Override public void run() throws Exception {
        long base = currentProgram.getImageBase().getOffset();
        for (String row : Files.readAllLines(Paths.get(getScriptArgs()[0]))) {
            monitor.checkCancelled();
            String[] parts = row.split("\t", 2);
            if (parts.length != 2) continue;
            Function f = currentProgram.getFunctionManager().getFunctionAt(toAddr(base + Long.decode(parts[0])));
            if (f == null || !f.getSymbol().getSource().equals(SourceType.DEFAULT)) continue;
            // Flat names avoid claiming a recovered namespace or type layout.
            String name = parts[1].replaceAll("[^A-Za-z0-9_]", "_");
            if (!name.isEmpty()) f.setName(name, SourceType.USER_DEFINED);
        }
    }
}
