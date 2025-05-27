# Firmware Download

<link rel="stylesheet" href="_media/firmware-selector.css">

<div class="firmware-selector">
<div class="header">
<h2>🔧 Firmware Selector</h2>
<p>Choose your keyboard layout and download the right firmware</p>
</div>

<div class="progress-indicator">
<div class="step active" id="step1">1</div>
<div class="step-connector" id="connector1"></div>
<div class="step" id="step2">2</div>
<div class="step-connector" id="connector2"></div>
<div class="step" id="step3">3</div>
</div>

<div class="form-group">
<label for="layout-input">Step 1: Select Your Keyboard Layout</label>
<div class="help-text">Start typing to search, or click to browse all available layouts</div>
<div class="dropdown-container">
<input 
type="text" 
id="layout-input" 
class="dropdown-input" 
placeholder="Search for your keyboard layout..."
autocomplete="off"
>
<div class="dropdown-list" id="layout-dropdown"></div>
</div>
</div>

<div class="form-group version-group" id="version-group">
<label for="version-select">Step 2: Choose Firmware Version</label>
<div class="help-text">Select "Most recent" for the latest stable version (recommended)</div>
<select class="version-select" id="version-select">
<option value="latest">Most recent (recommended)</option>
<option value="v2.1.0">v2.1.0 (Stable)</option>
<option value="v2.0.5">v2.0.5</option>
<option value="v2.0.4">v2.0.4</option>
<option value="v2.0.3">v2.0.3</option>
<option value="v1.9.2">v1.9.2</option>
<option value="v1.9.1">v1.9.1</option>
<option value="v1.8.5">v1.8.5</option>
</select>
</div>

<div class="download-section" id="download-section">
<div class="help-text">Step 3: Download Your Firmware</div>
<button class="download-btn" id="download-btn">
📥 Download Firmware
</button>
</div>
</div>

<script src="_media/firmware-selector.js"></script>
