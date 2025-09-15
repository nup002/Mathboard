// firmware-download-plugin.js
(function () {
  // Plugin configuration
  const config = {
    githubUser: 'YOUR_USERNAME',
    githubRepo: 'YOUR_REPO',
    releaseTag: 'v1.0.0',
    layouts: [
      'canadian_french',
      'canadian_multilingual',
      'colemak',
      'croatian',
      'czech_mac_ansi',
      'danish',
      'dutch',
      'finnish',
      'french',
      'german',
      'german_mac',
      'hungarian',
      'icelandic',
      'italian',
      'japanese',
      'korean',
      'norwegian',
      'polish',
      'portuguese',
      'russian',
      'slovak',
      'slovenian',
      'spanish',
      'swedish',
      'swiss_french',
      'swiss_german',
      'turkish',
      'uk',
      'us',
      'us_dvorak',
      'us_international'
    ]
  };

  // Plugin CSS with dark mode support
  const css = `
    .firmware-downloader {
      max-width: 800px;
      margin: 20px auto;
      background: var(--base-background-color, white);
      border-radius: 15px;
      box-shadow: 0 4px 20px rgba(0,0,0,0.1);
      overflow: hidden;
      border: 1px solid var(--border-color, #e0e0e0);
    }

    /* Dark mode compatibility */
    [data-theme="dark"] .firmware-downloader {
      background: var(--base-background-color, #1c2128);
      border-color: var(--border-color, #30363d);
      box-shadow: 0 4px 20px rgba(0,0,0,0.3);
    }

    .firmware-header {
      background: linear-gradient(135deg, #0f4c75 0%, #3282b8 100%);
      color: white;
      padding: 30px;
      text-align: center;
    }

    .firmware-header h2 {
      font-size: 2em;
      margin-bottom: 10px;
      font-weight: 300;
    }

    .firmware-header p {
      font-size: 1.1em;
      opacity: 0.9;
    }

    .firmware-content {
      padding: 30px;
    }

    .firmware-search {
      margin-bottom: 25px;
    }

    .firmware-search input {
      width: 100%;
      padding: 12px 16px;
      font-size: 1em;
      border: 2px solid var(--border-color, #e0e0e0);
      border-radius: 8px;
      outline: none;
      transition: all 0.3s ease;
      background: var(--base-background-color, white);
      color: var(--text-color-base, #333);
    }

    /* Dark mode input styling */
    [data-theme="dark"] .firmware-search input {
      background: var(--base-background-color, #0d1117);
      color: var(--text-color-base, #c9d1d9);
      border-color: var(--border-color, #30363d);
    }

    .firmware-search input:focus {
      border-color: #3282b8;
      box-shadow: 0 0 0 3px rgba(50, 130, 184, 0.1);
    }

    [data-theme="dark"] .firmware-search input:focus {
      box-shadow: 0 0 0 3px rgba(50, 130, 184, 0.2);
    }

    .firmware-grid {
      display: grid;
      grid-template-columns: repeat(auto-fit, minmax(280px, 1fr));
      gap: 12px;
      margin-bottom: 20px;
    }

    .firmware-item {
      background: var(--base-background-color, #f8f9fa);
      border: 2px solid var(--border-color, #e9ecef);
      border-radius: 8px;
      padding: 16px;
      transition: all 0.3s ease;
      cursor: pointer;
      display: flex;
      justify-content: space-between;
      align-items: center;
    }

    /* Dark mode item styling */
    [data-theme="dark"] .firmware-item {
      background: var(--base-background-color, #21262d);
      border-color: var(--border-color, #30363d);
    }

    .firmware-item:hover {
      border-color: #3282b8;
      background: #e8f2f8;
      transform: translateY(-1px);
      box-shadow: 0 3px 10px rgba(0,0,0,0.1);
    }

    /* Dark mode hover styling */
    [data-theme="dark"] .firmware-item:hover {
      background: #1a4052;
      box-shadow: 0 3px 10px rgba(0,0,0,0.3);
    }

    .firmware-name {
      font-weight: 600;
      font-size: 1em;
      color: var(--text-color-base, #0f4c75);
    }

    /* Dark mode text styling */
    [data-theme="dark"] .firmware-name {
      color: var(--text-color-base, #58a6ff);
    }

    .firmware-download-btn {
      background: linear-gradient(135deg, #0f4c75 0%, #3282b8 100%);
      color: white;
      border: none;
      padding: 8px 14px;
      border-radius: 5px;
      cursor: pointer;
      font-weight: 500;
      font-size: 0.9em;
      transition: all 0.3s ease;
    }

    .firmware-download-btn:hover {
      transform: scale(1.05);
      box-shadow: 0 3px 10px rgba(50, 130, 184, 0.3);
    }

    .firmware-no-results {
      text-align: center;
      padding: 30px;
      color: var(--text-color-tertiary, #666);
      font-size: 1em;
      display: none;
    }

    /* Dark mode no results styling */
    [data-theme="dark"] .firmware-no-results {
      color: var(--text-color-tertiary, #8b949e);
    }

    @media (max-width: 600px) {
      .firmware-grid {
        grid-template-columns: 1fr;
      }

      .firmware-content {
        padding: 20px;
      }

      .firmware-header {
        padding: 20px;
      }

      .firmware-header h2 {
        font-size: 1.5em;
      }
    }
  `;

  // Helper functions
  function formatLayoutName(layout) {
    return layout.split('_')
                 .map(word => word.charAt(0).toUpperCase() + word.slice(1))
                 .join(' ');
  }

  function generateDownloadUrl(layout) {
    return `https://github.com/${config.githubUser}/${config.githubRepo}/releases/download/${config.releaseTag}/mathpad_mp1a_${layout}_v1.0.0.uf2`;
  }

  function downloadFirmware(layout) {
    const url = generateDownloadUrl(layout);
    const link = document.createElement('a');
    link.href = url;
    link.download = `mathpad_mp1a_${layout}_v1.0.0.uf2`;
    document.body.appendChild(link);
    link.click();
    document.body.removeChild(link);
  }

  function createFirmwareDownloader() {
    const container = document.createElement('div');
    container.className = 'firmware-downloader';

    container.innerHTML = `
      <div class="firmware-header">
        <h2>MathPad MP1A Firmware</h2>
        <p>Download the firmware that matches your keyboard layout</p>
      </div>
      <div class="firmware-content">
        <div class="firmware-search">
          <input type="text" placeholder="Search for your keyboard layout (e.g., US, German, French, Colemak...)" id="firmwareSearchInput">
        </div>
        <div class="firmware-grid" id="firmwareGrid"></div>
        <div class="firmware-no-results" id="firmwareNoResults">
          <p>No layouts found matching your search. Try a different term or browse all available layouts above.</p>
        </div>
      </div>
    `;

    return container;
  }

  function renderLayouts(container, layoutsToShow = config.layouts) {
    const grid = container.querySelector('#firmwareGrid');
    const noResults = container.querySelector('#firmwareNoResults');

    grid.innerHTML = '';

    if (layoutsToShow.length === 0) {
      noResults.style.display = 'block';
      return;
    }

    noResults.style.display = 'none';
    layoutsToShow.forEach(layout => {
      const item = document.createElement('div');
      item.className = 'firmware-item';
      item.innerHTML = `
        <div class="firmware-name">${formatLayoutName(layout)}</div>
        <button class="firmware-download-btn" data-layout="${layout}">Download</button>
      `;

      // Add click handler for download button
      const downloadBtn = item.querySelector('.firmware-download-btn');
      downloadBtn.addEventListener('click', (e) => {
        e.stopPropagation();
        downloadFirmware(layout);
      });

      grid.appendChild(item);
    });
  }

  function initializeFirmwareDownloader(container) {
    const searchInput = container.querySelector('#firmwareSearchInput');

    // Initial render
    renderLayouts(container);

    // Search functionality
    searchInput.addEventListener('input', () => {
      const searchTerm = searchInput.value.toLowerCase();
      const filteredLayouts = config.layouts.filter(layout =>
        formatLayoutName(layout).toLowerCase().includes(searchTerm) ||
        layout.toLowerCase().includes(searchTerm)
      );
      renderLayouts(container, filteredLayouts);
    });

    // Dynamic theme detection and updating
    function updateTheme() {
      const isDark =
        document.documentElement.classList.contains('dark') ||
        document.body.classList.contains('dark') ||
        document.documentElement.getAttribute('data-theme') === 'dark' ||
        document.body.getAttribute('data-theme') === 'dark' ||
        // Check for docsify-darklight-theme specific indicators
        window.getComputedStyle(document.body).getPropertyValue('--base-background-color').includes('#') ||
        // Fallback: check if background is dark
        (window.getComputedStyle(document.body).backgroundColor === 'rgb(13, 17, 23)') ||
        (window.getComputedStyle(document.body).backgroundColor === 'rgb(22, 27, 34)');

      if (isDark) {
        container.classList.add('force-dark');
      } else {
        container.classList.remove('force-dark');
      }
    }

    // Initial theme check
    updateTheme();

    // Watch for theme changes
    const observer = new MutationObserver((mutations) => {
      mutations.forEach((mutation) => {
        if (mutation.type === 'attributes' &&
            (mutation.attributeName === 'class' ||
             mutation.attributeName === 'data-theme')) {
          updateTheme();
        }
      });
    });

    // Observe both html and body for theme changes
    observer.observe(document.documentElement, {
      attributes: true,
      attributeFilter: ['class', 'data-theme']
    });
    observer.observe(document.body, {
      attributes: true,
      attributeFilter: ['class', 'data-theme']
    });

    // Also listen for storage events (theme persistence)
    window.addEventListener('storage', updateTheme);

    // Listen for custom events that might indicate theme changes
    window.addEventListener('darklighttheme', updateTheme);
    window.addEventListener('themechange', updateTheme);

    // Cleanup function (store observer reference for potential cleanup)
    container.themeObserver = observer;
  }

  // Docsify plugin
  function firmwareDownloadPlugin(hook, vm) {
    // Add CSS
    hook.ready(() => {
      const style = document.createElement('style');
      style.textContent = css;
      document.head.appendChild(style);
    });

    // Process markdown content
    hook.beforeEach((content) => {
      // Replace the firmware download placeholder with actual component
      return content.replace(
        /<!-- firmware-download -->/g,
        '<div id="firmware-download-placeholder"></div>'
      );
    });

    // After DOM is ready
    hook.doneEach(() => {
      const placeholder = document.getElementById('firmware-download-placeholder');
      if (placeholder) {
        const firmwareDownloader = createFirmwareDownloader();
        placeholder.parentNode.replaceChild(firmwareDownloader, placeholder);
        initializeFirmwareDownloader(firmwareDownloader);
      }
    });
  }

  // Configure plugin
  firmwareDownloadPlugin.config = function(userConfig) {
    Object.assign(config, userConfig);
  };

  // Install plugin
  if (typeof window !== 'undefined') {
    window.$docsify = window.$docsify || {};
    window.$docsify.plugins = (window.$docsify.plugins || []).concat(firmwareDownloadPlugin);
    window.firmwareDownloadPlugin = firmwareDownloadPlugin;

    // Auto-configure if not already configured
    if (!firmwareDownloadPlugin.configured) {
      firmwareDownloadPlugin.config({
        githubUser: 'Summa-Cogni',
        githubRepo: 'Mathpad',
        releaseTag: 'v1.0.0'
      });
      firmwareDownloadPlugin.configured = true;
    }
  }
})();
