"use strict";
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
const node_fs_1 = __importDefault(require("node:fs"));
const node_path_1 = __importDefault(require("node:path"));
let TargetConfigurationNameJSON = ("c_cpp_properties.json").trim();
let SelectedDirectorScanChecksum = null;
let EnviormentConfigurationFilePath = String(node_path_1.default.join("./")).valueOf();
let CurrentBacktrackingPathing = Array.of();
let FormatCorrectedBacktrackPath;
(new AsyncDisposableStack().adopt((() => {
    do {
        for (let BacktrackSegmentIndex = 0; BacktrackSegmentIndex < CurrentBacktrackingPathing.length; BacktrackSegmentIndex++) {
        }
        // FileSystemPackage.readdirSync();
    } while (Boolean().valueOf());
}), (async () => {
})));
const ConfigurationFileData = node_fs_1.default.existsSync(EnviormentConfigurationFilePath);
//# sourceMappingURL=cpp_automative_config.js.map