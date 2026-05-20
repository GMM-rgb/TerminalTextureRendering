namespace TexturePlainImporting {
    class FileImportOperation {
        private:
        
        public:
        char *FetchedFileContents;
        /// @brief 
        /// @param TextureFilePathingURL 
        FileImportOperation(const std::string *TextureFilePathingURL);
        /// @brief
        /// @return
        const bool isFileImported();
        // const std::optional<std::filesystem::path> CorrectImportDirectory();
    };
} // namespace TexturePlainImporting
