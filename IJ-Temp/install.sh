#!/bin/bash
echo "🚀 Installing IJ PROS Template..."

# Check for existing folder
if [ -d "IJ-Template" ]; then
  echo "⚠️ Error: 'IJ-Template' folder exists! Delete it first."
  exit 1
fi

# Check for git
if ! command -v git &> /dev/null; then
  echo "❌ Git not installed! Download: https://git-scm.com"
  exit 1
fi

# Clone repo
git clone https://github.com/IshanJakkulwar/IJ-Template.git || exit 1
cd IJ-Template/IJ-Temp || { echo "❌ Failed to enter project folder!"; exit 1; }

# Try to open in VSCode
if command -v code &> /dev/null; then
  echo "✅ Success! Opening VSCode..."
  code .
elif [ -d "/Applications/Visual Studio Code.app" ]; then
  echo "✅ Success! Opening VSCode..."
  open -a "Visual Studio Code" .
else
  echo "⚠️ VSCode not found. Install it from: https://code.visualstudio.com"
  echo "Project cloned at: $(pwd)"
fi
