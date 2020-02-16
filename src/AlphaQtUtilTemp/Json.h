#ifndef JSON_H
#define JSON_H

#include <QJsonArray>
#include <QJsonValue>
#include <QJsonObject>
#include <QJsonDocument>

struct JsonPrivate;

/**
* Qt �� JSON API ��д���ε����Բ������㣬������Ŀ�ľ����ܹ�ʹ�ô� "." ��·����ʽ���� Json �����ԣ�����
* "id" ���ʵ��Ǹ��ڵ��µ� id��"user.address.street" ���ʸ��ڵ��� user �� address �� street �����ԡ�
*
* JSON ���� (JSON �� key ������˫������������ֵ�в�ͬ�����ͣ���ֵ���Ͳ���˫�������������ַ����͵Ĳ���)��
* {
*     "id": 18191,
*     "user": {
*         "address": {
*             "street": "Wiessenstrasse",
*             "postCode": "100001"
*         },
*         "childrenNames": ["Alice", "Bob", "John"]
*     }
* }
*
* ���� Json ����: Json json(jsonString) or Json json(jsonFilePath, true)
* ���� Json �����ļ�: json.save("xxx.json")
*
* ���� id:     json.getInt("id")������ 18191
* ���� street: json.getString("user.address.street")������ "Wiessenstrasse"
* ���� childrenNames: json.getStringList("user.childrenNames") �õ��ַ����б�("Alice", "Bob", "John")
* ���� "user.address.postCode" �����ʹ�� json.set("user.address.postCode", "056231")
* ������ڵ������飬��ʹ�� json.getJsonArray(".") ��ȡ
*
* �����ȡ�����Բ����ڣ��򷵻�ָ����Ĭ��ֵ���� "database.username.firstName" �����ڣ�
* ���� json.getString("database.username.firstName", "defaultName")������Ҫ���ʵ����Բ����ڣ�
* �õ�����һ���յ� QJsonValue�����Է�������ָ����Ĭ��ֵ "defaultName"��
*
* ���Ҫ�޸ĵ����Բ����ڣ�����Զ����ȴ������ԣ�Ȼ����������ֵ��
*
* ע��: JSON �ļ�Ҫʹ�� UTF-8 ���롣
*/
class Json {
public:
	/**
	* ʹ�� JSON �ַ������ߴ��ļ���ȡ JSON ���ݴ��� Json ����
	* ��� fromFile Ϊ true�� �� jsonOrJsonFilePath Ϊ JSON �ļ���·��
	* ��� fromFile Ϊ false���� jsonOrJsonFilePath Ϊ JSON ���ַ�������
	*
	* @param jsonOrJsonFilePath JSON ���ַ������ݻ��� JSON �ļ���·��
	* @param fromFile Ϊ true���� jsonOrJsonFilePath Ϊ JSON �ļ���·����Ϊ false �� jsonOrJsonFilePath Ϊ JSON ���ַ�������
	*/
	explicit Json(const QString &jsonOrJsonFilePath = "{}", bool fromFile = false);
	~Json();

	// ��ֹ���ƹ���͸�ֵ, ��Ϊ ~Json() �л�ɾ�� JSON �����ݶ��� JsonPrivate
	Json(const Json &other) = delete;
	Json& operator=(const Json &other) = delete;

	bool isValid() const;        // JSON �Ƿ���Ч����Ч�� JSON ���� true�����򷵻� false
	QString errorString() const; // JSON ��Чʱ�Ĵ�����Ϣ

								 /**
								 * ��ȡ·�� path ��Ӧ���Ե�����ֵ
								 *
								 * @param path �� "." ��·����
								 * @param def ���Ҫ�ҵ����Բ�����ʱ���ص�Ĭ��ֵ
								 * @param fromNode �Ӵ˽ڵ㿪ʼ���ң����ΪĬ��ֵ QJsonObject()����� Json �ĸ��ڵ㿪ʼ����
								 * @return ����ֵ
								 */
	int         getInt(const QString &path, int def = 0, const QJsonObject &fromNode = QJsonObject()) const;
	bool        getBool(const QString &path, bool def = false, const QJsonObject &fromNode = QJsonObject()) const;
	double      getDouble(const QString &path, double def = 0.0, const QJsonObject &fromNode = QJsonObject()) const;
	QString     getString(const QString &path, const QString &def = QString(), const QJsonObject &fromNode = QJsonObject()) const;
	QStringList getStringList(const QString &path, const QJsonObject &fromNode = QJsonObject()) const;

	QJsonArray  getJsonArray(const QString &path, const QJsonObject &fromNode = QJsonObject()) const;
	QJsonValue  getJsonValue(const QString &path, const QJsonObject &fromNode = QJsonObject()) const;
	QJsonObject getJsonObject(const QString &path, const QJsonObject &fromNode = QJsonObject()) const;

	/**
	* @brief ���� path ��Ӧ�� Json ���Ե�ֵ
	* @param path  path �� "." ��·����
	* @param value ���������������������ַ�����QJsonValue, QJsonObject �ȣ�������ο� QJsonValue �Ĺ��캯��
	*/
	void set(const QString &path, const QJsonValue &value);
	void set(const QString &path, const QStringList &strings);

	/**
	* @brief ɾ�� path ��Ӧ������
	* @param path �� "." ��·����
	*/
	void remove(const QString &path);

	/**
	* @brief �� JSON ���浽 path ָ�����ļ�
	*
	* @param path �ļ���·��
	* @param pretty Ϊ true ʱ��ʽ�� JSON �ַ�����Ϊ false ��ʹ��ѹ����ʽȥ������Ŀհ��ַ�
	*/
	void save(const QString &path, bool pretty = true) const;

	/**
	* @brief �� Json ����ת��Ϊ JSON �ַ���
	* @param pretty Ϊ true ʱ��ʽ�� JSON �ַ�����Ϊ false ��ʹ��ѹ����ʽȥ������Ŀհ��ַ�
	* @return Json ������ַ�����ʾ
	*/
	QString toString(bool pretty = true) const;

public:
	JsonPrivate *d;
};

#endif // JSON_H