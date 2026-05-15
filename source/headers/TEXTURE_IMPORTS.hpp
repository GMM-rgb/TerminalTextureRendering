namespace TexturePlainImporting
{
    class FileImportOperation
    {
    private:
    public:
        char *FetchedFileContents;
        FileImportOperation(std::string TextureFilePathingURL);
        /// @brief
        /// @return
        const bool isFileImported();
    };
}
