<?php

// EEngine config file
// version: 2.1.1
// date: 2012-08-09


// ����� ��� �����
define("SITE_NAME", "������������� ��������������� �������� �����������");
define("SITE_SHORT_NAME", "����");

// ����� ��������� ���������������� �����
define("OPERATE_MODE", "N");                            // ����� ������: N - ����������, S - ����������� ������, B - ���� ������������
define("BLOCKED_MODE_PAGE", "blocked.tpl");             // ��������, ������������ ����������� � ������ ���������� �����
define("SERVICE_MODE_PAGE", "service.tpl");             // ��������, ������������ ����������� � ������ ����������� �����
define("SERVICE_MODE_LOGIN_PAGE", "office/");     		// �������� ����������� ������������� � ������ ����������� �����
define("MAIL_LOGIN_PAGE", "mail/");       				// �������� ����������� ������������� � �������� ����
define("ADMIN_USERGROUP_ID", 1);                        // ID ����������������� ������ �������������
define("INHERIT_TEMPLATES", 1);							// ����������� �� ������ ������������ ��������
define("COUNT_LOADING_TIME", 0);						// ������� �� ����� �������� ������� � ���������� sql-��������
define("CACHE_TIME", 0);								// ����� (� ��������) ����������� �������: 0 - ����������� ���������

// ������������ �����, ����� ������� ���������� ����� �� ����
// ������ ������� ���� ������� - �����, ������ ���������� - "��������" �� �����, ������ ���������� - �������� ����� ������
$DOMAINS = array(
	"nsau" => array(true, 0),
	"portal.nsau.edu.ru" => array(false, 0),
	"nsau.edu.ru" => array(false, 0),
 "xn--80af3a0a.xn--p1ai" => array(false, 0),	"����.��" => array(false, 0),
	"vetfac.nsau.edu.ru" => array(false, 169),
	"nripk.ru" => array(false, 1775),
	"bulletin.nsau.edu.ru" => array(false, 1023)
	);

define("SATELLITE_DOMAINS", "nripk.ru");	// ������, ��� ������� ���������� �������� ������ � �������� ������, ������������� ����� ����� � ������� - domain1;domain2
define("AUTO_WWW_ALIAS", true);                         // �������������� ������������� ������ ���� www.example.com � example.com
define("DEFAULT_DOMAIN", "nsau.edu.ru");                // ���� ���������� ����� � ������, �� ���������� � ������, ����� ������� �����

if (isset($DOMAINS[$_SERVER["SERVER_NAME"]]))
// ����� ������ � ������, ��������� ���
{
	define("APPLIED_DOMAIN", $_SERVER["SERVER_NAME"]);
}

elseif (AUTO_WWW_ALIAS
	&& (strpos($_SERVER["SERVER_NAME"], "www.") === 0)
	&& isset($DOMAINS[substr($_SERVER["SERVER_NAME"], 4)]))
// � ������ ������ ����� �� �����, �� ��� WWW, ��������� ���
{
	define("APPLIED_DOMAIN", substr($_SERVER["SERVER_NAME"], 4));
}

else
// ����� �� ������ � ������, ��������� ����� �� ���������
{
	define("APPLIED_DOMAIN", DEFAULT_DOMAIN);
}


// �� ������������ ������ ����������, "����" �� ��� �� �������� �������
define("AT_HOME", $DOMAINS[APPLIED_DOMAIN][0]);




if (AT_HOME)
// ...� � ����������� �� ����� ����� ��������� �������, �� � �������� �����...
// ..."����":
{
$DEBUG_LEVEL = 3;                                     // ������� �������: 0 - ���, 1 - ���������, 2 - ������, 3 - ���������� (��� ������� ��)
	define("DEBUG_ONLY_FOR_ADMIN", false);                // ������� ������ ��� ���������������
	define("DB_TYPE", "mysql");                           // ��� ���� ������
	define("DB_HOST", "localhost");                       // ������ ��
	define("DB_PORT", 3306);                              // ���� ������� ��
	define("DB_USER", "root");                                // ��� ������������ ��
	define("DB_PASS", "f55YsWu7VxeGH9dY");                                // ������ ������������ ��
	define("DB_NAME", "nsau");                                // ��� ���� ������

	define("DOC_ROOT", $_SERVER["DOCUMENT_ROOT"] . "/");  // ������ ������� � �������� ������� (FS)
	define("INCLUDES", DOC_ROOT . "includes/");           // FS-���� � ��������
	define("HTTP_ROOT", "/");                             // HTTP-������ �����
}

else
// ...�� �������� �������:
{
	$DEBUG_LEVEL = 3;                                      // ������� �������: 0 - ���, 1 - ���������, 2 - ������, 3 - ���������� (��� ������� ��)
	define("DEBUG_ONLY_FOR_ADMIN", false);                  // ������� ������ ��� ���������������
	define("DB_TYPE", "mysql");                            // ��� ���� ������
	define("DB_HOST", "localhost");                        // ������ ��
	define("DB_PORT", 3306);                               // ���� ������� ��
	define("DB_USER", "nsau");                                 // ��� ������������ ��
	define("DB_PASS", "EbAhRwRcLvpxHATe");                                 // ������ ������������ ��
	define("DB_NAME", "nsau");                                 // ��� ���� ������

	define("DOC_ROOT", $_SERVER["DOCUMENT_ROOT"] . "/");   // ������ ������� � �������� ������� (FS)
	define("INCLUDES", DOC_ROOT . "includes/");            // FS-���� � ��������
	define("HTTP_ROOT", "/");                              // HTTP-������ �����
}


 

// ����� �������� ���� � ���������
define("MAIN_LANGUAGE", "ru_RU");
define("CODEPAGE", "cp1251");


// ����� ������� �������� ����� � ��������� (� �����)
define("TIMEZONE_OFFSET_HOURS", 7);  // ������ 6, ������ 7
define("TIMEZONE", "Asia/Novosibirsk");

define("ENGINE_DB_PREFIX", "engine_");                   // ������� ���� ������ ��� ������
define("AUTH_DB_PREFIX", "auth_");                       // ������� ���� ������ ��� ������� �����������
define("ALLOW_AUTH", true);                              // ��������� �� ����������� �������������
define("SIMPLE_NODEGROUPS_INHERITANCE", false);          // ������������ �� ���������� ������������ nodegroups
define("ALLOW_FOLDEROPTIONS", false);                    // ��������� �� ������������� ����� ��� ����������� �����


// ����������� ������ ������ (������)
define("SESSION_HANDLER_VARNAME", "ESessionHandler");     // ��� ���������� ��� �������������� ����������� ������ (false - �� ������������)
ini_set("session.gc_maxlifetime", 180000);                 // ����� "�����" ������ ������������ �� ���������


// ����� �������� ����� � ����
define("THEMES_DIR", "themes/");                         // ��� ����� ���
define("IMAGES_DIR", "images/");                         // ��� ����� �����������
define("STYLES_DIR", "styles/");                         // ��� ����� ������
define("SCRIPTS_DIR", "scripts/");                       // ��� ����� ��������
define("FILES_DIR", "files/");                           // ��� ����� ���������������� ������

define("CLASS_EXT", ".class.php");                           // ���������� ����� ��� �������
define("TEMPLATE_EXT", ".tpl");                          // ���������� ����� ��� ��������
define("PRETEMPLATE_EXT", ".ptpl");                      // ���������� ����� ��� ��������������� �������� (������������ �� ��������� �������)
define("ALLOW_PRETEMPLATES", true);                      // ��������� ������������� ��������������� ��������

define("DEFAULT_MAIN_TEMPLATE", "_mainnew");                // ��� ��������� ������� �� ���������
define("HTTP403_TEMPLATE", "_403");                      // ��� ������� �������� HTTP 403 (������ ����� ����)
define("HTTP404_TEMPLATE", "_404");                      // ��� ������� �������� HTTP 404 (������ ����� ����)


// ��������� ���������� �������� ����
define("APPEND_KEYWORDS", false);                        // ���������, � �� �������� �������� ����� ��� �������� ("before"/"after"/false)
define("KEYWORDS_GLUE", ", ");                           // ������ ��� ������� �������� ����

define("AJAX_REQUEST_MARKER", "application/text+xml+javascript");			// ����������-������, ������������ � ajax-�������, ����� ������ ��� �� ����������

?>
