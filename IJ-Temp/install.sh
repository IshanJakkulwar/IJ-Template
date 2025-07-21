#!/bin/bash
echo "🚀 Installing IJ PROS Template..."

# Check for existing folder to avoid conflicts
if [ -d "IJ-Template" ]; then
  echo "⚠️ Error: 'IJ-Template' folder already exists! Delete it first."
  exit 1
fi

# Check for git/VSCode
if ! command -v git &> /dev/null; then
  echo "❌ Git not installed! Download: https://git-scm.com"
  exit 1
fi

if ! command -v code &> /dev/null; then
  echo "❌ VSCode not installed or 'code' CLI not in PATH. Fix: https://code.visualstudio.com/docs/setup/mac"
fi

# Clone and setup
git clone https://github.com/IshanJakkulwar/IJ-Template.git || exit 1
cd IJ-Template/IJ-Temp || { echo "❌ Failed to enter project folder!"; exit 1; }
echo "✅ Success! Opening VSCode..."
code .
