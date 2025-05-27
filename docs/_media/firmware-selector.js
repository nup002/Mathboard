// Sample keyboard layouts data
const keyboardLayouts = [
    "Planck Rev6", "Planck Rev5", "Planck EZ", "Planck Light",
    "Preonic Rev3", "Preonic Rev2", "Preonic Rev1",
    "Corne (CRKBD)", "Corne Light", "Corne Cherry",
    "Lily58", "Lily58 Pro", "Lily58 Glow",
    "Kyria Rev1", "Kyria Rev2", "Kyria Rev3",
    "Sofle V1", "Sofle V2", "Sofle RGB",
    "Iris Rev4", "Iris Rev5", "Iris Rev6",
    "Levinson", "Levinson Rev2", "Levinson Rev3",
    "Helix 5 Rows", "Helix 4 Rows",
    "Ergodox EZ", "Ergodox Infinity", "Ergodox Original",
    "Moonlander", "Planck EZ Glow",
    "Discipline V1", "Discipline V2",
    "BFO-9000", "Quefrency Rev1", "Quefrency Rev2",
    "Sinc Rev1", "Sinc Rev2",
    "Redox", "Redox Wireless",
    "Dactyl", "Dactyl Manuform 4x6", "Dactyl Manuform 5x6",
    "Let's Split", "Let's Split EH",
    "Nyquist Rev2", "Nyquist Rev3",
    "Viterbi Rev1", "Viterbi Rev2",
    "Fourier", "Laplace",
    "Chocopad", "Sweet16"
];

// State management
let selectedLayout = null;
let filteredLayouts = [...keyboardLayouts];

// DOM elements
const layoutInput = document.getElementById('layout-input');
const layoutDropdown = document.getElementById('layout-dropdown');
const versionGroup = document.getElementById('version-group');
const versionSelect = document.getElementById('version-select');
const downloadSection = document.getElementById('download-section');
const downloadBtn = document.getElementById('download-btn');

// Progress steps
const step1 = document.getElementById('step1');
const step2 = document.getElementById('step2');
const step3 = document.getElementById('step3');
const connector1 = document.getElementById('connector1');
const connector2 = document.getElementById('connector2');

// Initialize the dropdown
function initializeDropdown() {
    renderDropdownItems(keyboardLayouts);
}

// Render dropdown items
function renderDropdownItems(items) {
    layoutDropdown.innerHTML = '';

    if (items.length === 0) {
        const noResults = document.createElement('div');
        noResults.className = 'no-results';
        noResults.textContent = 'No layouts found matching your search';
        layoutDropdown.appendChild(noResults);
        return;
    }

    items.forEach(layout => {
        const item = document.createElement('div');
        item.className = 'dropdown-item';
        item.textContent = layout;
        item.addEventListener('click', () => selectLayout(layout));
        layoutDropdown.appendChild(item);
    });
}

// Filter layouts based on search
function filterLayouts(searchTerm) {
    const filtered = keyboardLayouts.filter(layout =>
        layout.toLowerCase().includes(searchTerm.toLowerCase())
    );
    renderDropdownItems(filtered);
}

// Select a layout
function selectLayout(layout) {
    selectedLayout = layout;
    layoutInput.value = layout;
    layoutInput.classList.add('selected-layout');
    hideDropdown();
    showVersionStep();
}

// Show dropdown
function showDropdown() {
    layoutDropdown.classList.add('show');
}

// Hide dropdown
function hideDropdown() {
    layoutDropdown.classList.remove('show');
}

// Show version selection step
function showVersionStep() {
    // Update progress
    step1.classList.remove('active');
    step1.classList.add('completed');
    connector1.classList.add('completed');
    step2.classList.add('active');

    // Show version group with animation
    setTimeout(() => {
        versionGroup.classList.add('show');
    }, 200);
}

// Show download step
function showDownloadStep() {
    // Update progress
    step2.classList.remove('active');
    step2.classList.add('completed');
    connector2.classList.add('completed');
    step3.classList.add('active');

    // Show download section with animation
    setTimeout(() => {
        downloadSection.classList.add('show');
    }, 200);
}

// Handle download
function handleDownload() {
    const version = versionSelect.value;
    const fileName = `${selectedLayout.replace(/\s+/g, '_').toLowerCase()}_${version}.bin`;

    // In a real implementation, this would trigger an actual download
    // For now, we'll just show an alert
    alert(`Downloading: ${fileName}\n\nLayout: ${selectedLayout}\nVersion: ${version}`);

    // You would replace this with actual download logic:
    // window.open(`/firmware/${fileName}`, '_blank');
}

// Event listeners
layoutInput.addEventListener('input', (e) => {
    const searchTerm = e.target.value;
    filterLayouts(searchTerm);
    showDropdown();

    // Reset selection if input is manually changed
    if (selectedLayout && e.target.value !== selectedLayout) {
        selectedLayout = null;
        layoutInput.classList.remove('selected-layout');
        versionGroup.classList.remove('show');
        downloadSection.classList.remove('show');

        // Reset progress
        step1.classList.add('active');
        step1.classList.remove('completed');
        step2.classList.remove('active', 'completed');
        step3.classList.remove('active', 'completed');
        connector1.classList.remove('completed');
        connector2.classList.remove('completed');
    }
});

layoutInput.addEventListener('focus', () => {
    if (!selectedLayout) {
        renderDropdownItems(keyboardLayouts);
        showDropdown();
    }
});

layoutInput.addEventListener('click', () => {
    if (!selectedLayout) {
        renderDropdownItems(keyboardLayouts);
        showDropdown();
    }
});

// Hide dropdown when clicking outside
document.addEventListener('click', (e) => {
    if (!e.target.closest('.dropdown-container')) {
        hideDropdown();
    }
});

// Handle version selection
versionSelect.addEventListener('change', () => {
    if (selectedLayout && versionSelect.value) {
        showDownloadStep();
    }
});

// Handle download button
downloadBtn.addEventListener('click', handleDownload);

// Initialize on page load
document.addEventListener('DOMContentLoaded', initializeDropdown);

// Keyboard navigation for dropdown
layoutInput.addEventListener('keydown', (e) => {
    const items = layoutDropdown.querySelectorAll('.dropdown-item');
    const selectedItem = layoutDropdown.querySelector('.dropdown-item.selected');
    let currentIndex = Array.from(items).indexOf(selectedItem);

    switch (e.key) {
        case 'ArrowDown':
            e.preventDefault();
            if (currentIndex < items.length - 1) {
                if (selectedItem) selectedItem.classList.remove('selected');
                items[currentIndex + 1].classList.add('selected');
            } else if (items.length > 0) {
                if (selectedItem) selectedItem.classList.remove('selected');
                items[0].classList.add('selected');
            }
            break;
        case 'ArrowUp':
            e.preventDefault();
            if (currentIndex > 0) {
                if (selectedItem) selectedItem.classList.remove('selected');
                items[currentIndex - 1].classList.add('selected');
            } else if (items.length > 0) {
                if (selectedItem) selectedItem.classList.remove('selected');
                items[items.length - 1].classList.add('selected');
            }
            break;
        case 'Enter':
            e.preventDefault();
            if (selectedItem) {
                selectLayout(selectedItem.textContent);
            }
            break;
        case 'Escape':
            hideDropdown();
            break;
    }
});
