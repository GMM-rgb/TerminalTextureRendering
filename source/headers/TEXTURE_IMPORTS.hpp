#pragma once
/**
 * @namespace `TexturePlainImporting`
*/
namespace TexturePlainImporting {
    class FileImportOperation {
        private:
        
        public:
        char *FetchedFileContents;
        /// @brief 
        /// @param TextureFilePathingURL 
        FileImportOperation(std::string *TextureFilePathingURL);
        /// @brief
        /// @return
        const bool isFileImported();
    };
} /// namespace TexturePlainImporting
