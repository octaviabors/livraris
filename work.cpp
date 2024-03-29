else if(formatChunk->audioFormat == WavAudioFormat::IeeeFloat) {
        if(formatChunk->numChannels == 1 && formatChunk->bitsPerSample == 32)
            _format = BufferFormat::MonoFloat;
        else if(formatChunk->numChannels == 2 && formatChunk->bitsPerSample == 32)
            _format = BufferFormat::StereoFloat;
        else if(formatChunk->numChannels == 1 && formatChunk->bitsPerSample == 64)
            _format = BufferFormat::MonoDouble;
        else if(formatChunk->numChannels == 2 && formatChunk->bitsPerSample == 64)
            _format = BufferFormat::StereoDouble;
        else {
            Error() << "Audio::WavImporter::openData(): IEEE with unsupported channel count"
                    << formatChunk->numChannels << "with" << formatChunk->bitsPerSample
                    << "bits per sample";
            return;

  if(formatChunk->blockAlign != formatChunk->numChannels * formatChunk->bitsPerSample / 8 ||
       formatChunk->byteRate != formatChunk->sampleRate * formatChunk->blockAlign) {
        Error() << "Audio::WavImporter::openData(): the file is corrupted";
        return;
    }
//yes
  /* Fix the data endianness */
    if(hasBigEndianData != Utility::Endianness::isBigEndian()) {
        if(formatChunk->bitsPerSample == 16)
            Utility::Endianness::swapInPlace(Containers::arrayCast<std::uint16_t>(*_data));
        else if(formatChunk->bitsPerSample == 32)
            Utility::Endianness::swapInPlace(Containers::arrayCast<std::uint32_t>(*_data));
