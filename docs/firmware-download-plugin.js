// firmware-download-plugin.js
(function () {
  // Plugin configuration
  const config = {
    githubUser: 'Summa-Cogni',
    githubRepo: 'Mathpad',
    releaseTag: 'v1.0.0',
    layouts: [
      'canadian_multilingual',
      'croatian',
      'czech',
      'czech_mac_ansi',
      'czech_mac_iso',
      'danish',
      'uk',
      'us_ansi',
      'us_international',
      'estonian',
      'finnish',
      'french',
      'french_afnor',
      'bepo',
      'belgian',
      'canadian_french',
      'swiss_fr',
      'french_mac_iso',
      'german',
      'swiss_de',
      'german_mac_iso',
      'hungarian',
      'icelandic',
      'italian',
      'italian_mac_ansi',
      'italian_mac_iso',
      'japanese',
      'latvian',
      'lithuanian_azerty',
      'norwegian',
      'portuguese',
      'portuguese_mac_iso',
      'brazilian_abnt2',
      'romanian',
      'serbian_latin',
      'slovenian',
      'spanish',
      'spanish_dvorak',
      'spanish_latin_america',
      'swedish',
      'turkish_f',
      'turkish_q',
      'colemak',
      'dvorak',
      'dvorak_fr',
      'dvorak_programmer',
      'norman',
      'workman',
      'workman_zxcvm'
    ]
  };

  // Plugin CSS using docsify-darklight-theme CSS variables
  const css = `
    .firmware-downloader {
      max-width: 800px;
      margin: 20px auto;
      background: var(--firmware_download_plugin_container_background, white);
      border-radius: 15px;
      box-shadow: 0 4px 20px var(--firmware_download_plugin_container_shadow, rgba(0,0,0,0.1));
      overflow: hidden;
      border: 1px solid var(--firmware_download_plugin_container_border, #e0e0e0);
    }

    .firmware-header {
      background: var(--firmware_download_plugin_header_color, white);
      color: white;
      padding: 10px;
      text-align: center;
    }

    .firmware-header h2 {
      font-size: 2em;
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
      margin-bottom: 0px;
    }

    .firmware-search input {
      width: 100%;
      padding: 12px 16px;
      font-size: 1em;
      border: 2px solid var(--firmware_download_plugin_input_border, #e0e0e0);
      border-radius: 8px;
      outline: none;
      transition: all 0.3s ease;
      background: var(--firmware_download_plugin_input_background, white);
      color: var(--firmware_download_plugin_input_color, #333);
    }

    .firmware-search input:focus {
      border-color: #3282b8;
      box-shadow: 0 0 0 3px rgba(50, 130, 184, 0.1);
    }

    .firmware-grid {
      display: grid;
      grid-template-columns: repeat(auto-fit, minmax(280px, 1fr));
      gap: 12px;
      margin-bottom: 20px;
    }

    .firmware-item {
      background: var(--firmware_download_plugin_item_background, #f8f9fa);
      border: 2px solid var(--firmware_download_plugin_item_border, #e9ecef);
      border-radius: 8px;
      padding: 8px;
      transition: all 0.3s ease;
      cursor: pointer;
      display: flex;
      justify-content: space-between;
      align-items: center;
    }

    .firmware-item:hover {
      border-color: #3282b8;
      background: var(--firmware_download_plugin_item_hover_background, #e8f2f8);
      transform: translateY(-1px);
      box-shadow: 0 3px 10px rgba(0,0,0,0.1);
    }

    .firmware-name {
      font-weight: 600;
      font-size: 1em;
      color: var(--firmware_download_plugin_text_color, #0f4c75);
    }

    .firmware-download-btn {
      background: linear-gradient(135deg, #0fac75 0%, #0f8c25 100%);
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
      color: var(--firmware_download_plugin_text_secondary, #666);
      font-size: 1em;
      display: none;
    }

    @media (max-width: 600px) {
      .firmware-grid {
        grid-template-columns: 1fr;
      }
      
      .firmware-content {
        padding: 20px;
      }
      
      .firmware-header h1 {
        font-size: 1.5em;
      }
    }
  `;

  // Helper functions
  function formatLayoutName(layout) {
    // Handle special cases for better formatting
    const specialCases = {
      'us_ansi': 'US ANSI (standard US layout)',
      'us_international': 'US International',
      'canadian_multilingual': 'Canadian Multilingual',
      'canadian_french': 'Canadian French',
      'czech_mac_ansi': 'Czech Mac ANSI',
      'czech_mac_iso': 'Czech Mac ISO',
      'french_afnor': 'French AFNOR',
      'bepo': 'BÉPO',
      'belgian': 'Belgian',
      'swiss_fr': 'Swiss French',
      'french_mac_iso': 'French Mac ISO',
      'swiss_de': 'Swiss German',
      'german_mac_iso': 'German Mac ISO',
      'italian_mac_ansi': 'Italian Mac ANSI',
      'italian_mac_iso': 'Italian Mac ISO',
      'lithuanian_azerty': 'Lithuanian AZERTY',
      'portuguese_mac_iso': 'Portuguese Mac ISO',
      'brazilian_abnt2': 'Brazilian ABNT2',
      'serbian_latin': 'Serbian Latin',
      'spanish_dvorak': 'Spanish Dvorak',
      'spanish_latin_america': 'Spanish Latin America',
      'turkish_f': 'Turkish F',
      'turkish_q': 'Turkish Q',
      'colemak': 'Colemak',
      'dvorak': 'Dvorak',
      'dvorak_fr': 'Dvorak French',
      'dvorak_programmer': 'Dvorak Programmer',
      'norman': 'Norman',
      'workman': 'Workman',
      'workman_zxcvm': 'Workman ZXCVM',
      'uk': 'UK'
    };

    if (specialCases[layout]) {
      return specialCases[layout];
    }

    return layout.split('_')
                 .map(word => word.charAt(0).toUpperCase() + word.slice(1))
                 .join(' ');
  }

  function generateDownloadUrl(layout) {
    return `https://github.com/${config.githubUser}/${config.githubRepo}/releases/download/firmware-${config.releaseTag}/mathpad_mp1a_${layout}_${config.releaseTag}.uf2`;
  }

  function downloadFirmware(layout) {
    const url = generateDownloadUrl(layout);
    const link = document.createElement('a');
    link.href = url;
    link.download = `mathpad_mp1a_${layout}_${config.releaseTag}uf2`;
    document.body.appendChild(link);
    link.click();
    document.body.removeChild(link);
  }

  function createFirmwareDownloader() {
    const container = document.createElement('div');
    container.className = 'firmware-downloader';

    container.innerHTML = `
      <div class="firmware-header">
        <div class="firmware-search">
          <input type="text" placeholder="Search for your keyboard layout (e.g., US, German, French, Colemak...)" id="firmwareSearchInput">
        </div>
      </div>
      <div class="firmware-content">
        <div class="firmware-grid" id="firmwareGrid"></div>
        <div class="firmware-no-results" id="firmwareNoResults">
          <p>No layouts found matching your search.<br/> See <a href="http://mathpad.summacogni.com/#/compatibility?id=supported-keyboard-layouts">Supported Keyboard Layouts<\a></p>
        </div>
      <div>
        <p>${config.releaseTag}<br/>
        <a href="https://github.com/${config.githubUser}/${config.githubRepo}/releases/tag/firmware-${config.releaseTag}">Release page</a><br/>
        <a href="https://github.com/${config.githubUser}/${config.githubRepo}/tags">Older versions</a></p>
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