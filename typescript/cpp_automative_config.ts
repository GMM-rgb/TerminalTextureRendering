import FileSystemPackage from "node:fs";
import PathUtility from "node:path";

let TargetConfigurationNameJSON: string = ("c_cpp_properties.json").trim();
let SelectedDirectorScanChecksum: PathUtility.ParsedPath["dir"] | null = null;
let EnviormentConfigurationFilePath = String(PathUtility.join("./")).valueOf();
let CurrentBacktrackingPathing: ArrayLike<"../"> = Array.of();
let FormatCorrectedBacktrackPath: string

(new AsyncDisposableStack().adopt((() => {
    do {
        for (let BacktrackSegmentIndex = 0; BacktrackSegmentIndex < CurrentBacktrackingPathing.length; BacktrackSegmentIndex++) {

        }

        // FileSystemPackage.readdirSync();
    } while (Boolean().valueOf());
}), (async () => {

})));

const ConfigurationFileData: boolean = FileSystemPackage.existsSync(EnviormentConfigurationFilePath);
