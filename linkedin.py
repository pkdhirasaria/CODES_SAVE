from selenium import webdriver
from selenium.webdriver.chrome.options import Options
import os
from bs4 import BeautifulSoup


class LinkedIn:

    def __init__(self):
        chrome_options = Options()
        chrome_options.add_argument("--headless")
        chrome_options.add_argument("--window-size=1920x1080")
        chrome_options.add_argument("--disable-notifications")
        chrome_options.add_argument('--no-sandbox')
        chrome_options.add_argument('--verbose')
        chrome_options.add_experimental_option("prefs", {
            "download.default_directory": os.getcwd(),
            "download.prompt_for_download": False,
            "download.directory_upgrade": True,
            "safebrowsing_for_trusted_sources_enabled": False,
            "safebrowsing.enabled": False
        })
        chrome_options.add_argument('--disable-gpu')
        chrome_options.add_argument('--disable-software-rasterizer')
        # self.driver = webdriver.Chrome(options=chrome_options)
        self.driver = webdriver.Chrome()

    def url(self, url):
        self.driver.get(url)

    def login(self, username, password):
        self.driver.find_element_by_class_name('main__sign-in-link').click()
        self.driver.find_element_by_id('username').send_keys(username)
        self.driver.find_element_by_id('password').send_keys(password)
        self.driver.find_element_by_class_name('login__form_action_container').click()

    def get_profiles_per_page(self):
        return self.driver.find_elements_by_css_selector(
            '#main > div > div > div.ph0.pv2.artdeco-card.mb2 > ul > li > div > div > div.entity-result__content.entity-result__divider.pt3.pb3.t-12.t-black--light > div> div.t-roman.t-sans > div > span.entity-result__title-line.flex-shrink-1.entity-result__title-text--black > span > a')

    def get_pages(self):
        page_number = 1
        profile_urls = []
        while page_number <= 24:
            url = ""
            self.driver.get(url)
            elem = self.get_profiles_per_page()
            count = 0
            for e in elem:
                profile_urls.append((e.text.split('\n')[0], e.get_attribute("href")))
                count += 1
                # print(e.text.split('\n')[0])
            # print(page_number, count)
            page_number += 1
        return profile_urls

    def get_tenure(self, company, url):
        try:
            self.url(url)
            elem = l.driver.execute_script("return document.body.innerHTML;")
            soup = BeautifulSoup(elem, 'html.parser')
            company_duration = soup.select('#experience-section ul:nth-of-type(1)')[0].select('a span:nth-of-type(2)')
            for i in range(1, len(company_duration)):
                # print(company_duration[i-1])
                if company_duration[i - 1].text == company:
                    duration = company_duration[i].text.split(' ')
                    if 'yrs' in duration:
                        return int(duration[0]) * 12 + int(duration[2])
                    else:
                        return int(duration[0])
            return 0
        except Exception as e:
            return 6

    def get_average_ternure(self, company, profiles):
        total = 0
        for p in profiles:
            total += self.get_tenure(company, p[1])
        print(total)
        print(total // len(profiles))


page_number = 1
url = ""

l = LinkedIn()
l.url(url)
username = ""
password = ""
l.login(username, password)
company_name = ""
l.get_average_ternure(company_name, l.get_pages())
