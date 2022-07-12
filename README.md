![header with Plugin preview](docs/images/readmeHeader.png)
# Tremolo
This is a simple Tremolo Plugin created with [Juce](https://juce.com/).

## Contents
[Features](#features)  
[How to Install](#how-to-Install)
 
## Features
Four automatable parameters: 
 
* **Rate**: Tremolo frequency in Hz
* **Phase**: Generates offset of the Termeolo effect on channels clockwise (for positive values) or counterclockwise (for negative values) by the set value in degrees.
* **Depth**: Intensity of the effect in percent
* **Bypass**: Turns effect off (or on)

## How to Install

### Supported formats:

* VST3 
* AU

### Installation:
1. **Download** the latest [release](#releases) in the appropriate format
2. **Move the file** into the appropriate folder of your system, so that the host (e.g. DAW) recognizes the plug-in. (See [Installation locations](#installation-locations))
3. **Restart your host** (and **scan for new plugins** if necessary). The plugin should now be recognized and usable in the host.

### Releases
| Version 	| Format 	|   Link   	|
|:-------:	|:------:	|:--------:	|
| v1.0    	| AU     	| [Download](https://github.com/OliverHoenig/Tremolo/raw/main/Releases/v1.0/Tremolo.component.zip)	|
|         	| VST3   	| [Download](https://github.com/OliverHoenig/Tremolo/raw/main/Releases/v1.0/Tremolo.vst3.zip)	|

### Installation locations:


**_macOS_**

| Format | Direcotry Type |           Mac Installation Direcotry           |
|:------:|:--------------:|:----------------------------------------------:|
| VST3   | User           | ~/Library/Audio/Plug-Ins/VST3                  |
|        | System         | Macintosh HD/Library/Audio/Plug-Ins/VST3       |
| AU     | User           | ~/Library/Audio/Plug-Ins/Components            |
|        | System         | Macintosh HD/Library/Audio/Plug-Ins/Components |

**_Windows_**

| Format 	| Direcotry Type 	|          Mac Installation Direcotry          	|
|:------:	|:--------------:	|:--------------------------------------------:	|
| VST3   	| Shared         	| C:\Program Files\Common Files\VST3           	|




 ![preview of the plugin in logic x](docs/images/tremoloLogicX.png)
